#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/RTTI/Function.hpp>
#endif

#include <RED4ext/CNamePool.hpp>
#include <RED4ext/Detail/AddressHashes.hpp>
#include <RED4ext/RTTISystem.hpp>
#include <RED4ext/Relocation.hpp>
#include <RED4ext/RTTI/Property.hpp>
#include <RED4ext/Scripting/OpcodeHandlers.hpp>
#include <RED4ext/Scripting/Stack.hpp>

RED4EXT_INLINE bool RED4ext::rtti::Function::SetReturnType(CName aType)
{
    auto rtti = CRTTISystem::Get();
    auto type = rtti->GetType(aType);
    if (!type)
    {
        return false;
    }

    Property::Flags propertyFlags{};
    propertyFlags.isReturn = true;

    returnType = Property::Create(type, "__return", nullptr, 0, {}, propertyFlags);
    return returnType != nullptr;
}

RED4EXT_INLINE bool RED4ext::rtti::Function::AddParam(CName aType, const char* aName, bool aIsOut, bool aIsOptional)
{
    auto rtti = CRTTISystem::Get();
    auto type = rtti->GetType(aType);
    if (!type)
    {
        return false;
    }

    Property::Flags paramFlags{};
    paramFlags.isOut = aIsOut;
    paramFlags.isOptional = aIsOptional;

    auto param = Property::Create(type, aName, nullptr, unkAC, nullptr, paramFlags);
    if (!param)
    {
        return false;
    }

    params.PushBack(param);
    return true;
}

RED4EXT_INLINE bool RED4ext::rtti::Function::Execute(CStack* aStack) const
{
    if (!flags.isNative)
    {
        using executeScriptedFn_t = bool (*)(const Function*, CStack*, void*);
        static UniversalRelocFunc<executeScriptedFn_t> executeScriptedFn(
            Detail::AddressHashes::CBaseFunction_ExecuteScripted);
        return executeScriptedFn(this, aStack, nullptr);
    }

    using executeNativeFn_t = bool (*)(const Function*, CStack*);
    static UniversalRelocFunc<executeNativeFn_t> executeNativeFn(Detail::AddressHashes::CBaseFunction_ExecuteNative);
    return executeNativeFn(this, aStack);
}

RED4EXT_INLINE bool RED4ext::rtti::Function::Execute_(CStack* aStack) const
{
    if (!flags.isNative)
    {
        using func_t = bool (*)(const Function*, CStack*);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CBaseFunction_ExecuteScripted);
        return func(this, aStack);
    }

    char code[264];
    aStack->GenerateCode(code);
    CStackFrame stackFrame(aStack->GetContext(), code, aStack->unk10);

    return ExecuteNative(aStack, stackFrame);
}

RED4EXT_INLINE RED4ext::rtti::Function::Handler_t RED4ext::rtti::Function::GetHandler(uint32_t aIndex)
{
    static UniversalRelocPtr<Handler_t*> handlers(Detail::AddressHashes::CBaseFunction_Handlers);
    return handlers[aIndex];
}

RED4EXT_INLINE bool RED4ext::rtti::Function::ExecuteNative(CStack* aStack, CStackFrame& aFrame) const
{
    auto context = aStack->GetContext();
    auto resultType = aStack->GetResultType();
    auto resultAddress = aStack->GetResultAddr();

    if (!flags.isStatic)
    {
        if (!context)
        {
            context = aStack->context20;

            GetInvokable()->Execute(context, aFrame, resultAddress, resultType);
            return true;
        }

        auto func = GetHandler(GetRegIndex());
        if (func)
        {
            func(context, aFrame, resultAddress, resultType);
            return true;
        }

        return false;
    }

    auto func = OpcodeHandlers::Get(GetRegIndex() & 0xFF);
    if (!func)
    {
        return false;
    }

    func(context, &aFrame, resultAddress, resultType);
    return true;
}
