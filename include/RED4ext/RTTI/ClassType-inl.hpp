#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/RTTI/ClassType.hpp>
#endif

RED4EXT_INLINE RED4ext::rtti::ClassType::ClassType(CName aName, uint32_t aSize, Flags aFlags)
    : parent(nullptr)
    , name(aName)
    , computedName(rtti::IType::GetComputedName())
    , size(aSize)
    , flags(aFlags)
    , holderSize(0)
    , alignment(4)
    , props(Memory::RTTIAllocator::Get())
    , overriddenProps(Memory::RTTIAllocator::Get())
    , funcs(Memory::RTTIAllocator::Get())
    , staticFuncs(Memory::RTTIAllocator::Get())
    , funcsByName(Memory::RTTIAllocator::Get())
    , unkA8(Memory::RTTIAllocator::Get())
    , unkD8(0)
    , unkE0(0)
    , propsByName(Memory::RTTIAllocator::Get())
    , unk118(Memory::RTTIAllocator::Get())
    , unk128(Memory::RTTIAllocator::Get())
    , unk138(Memory::RTTIAllocator::Get())
    , unk148(Memory::RTTIAllocator::Get())
    , defaults(Memory::ScriptAllocator::Get())
    , unk180(Memory::RTTIAllocator::Get())
    , listeners(Memory::RTTIAllocator::Get())
    , eventTypeId(-1)
    , unk2C4(-1)
    , unk2C9(0xE6)
{
    std::memset(listening, 0, sizeof(listening));
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::ClassType::GetName() const
{
    return name;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ClassType::GetSize() const
{
    return size;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ClassType::GetAlignment() const
{
    return alignment;
}

RED4EXT_INLINE RED4ext::rtti::ERTTIType RED4ext::rtti::ClassType::GetType() const
{
    return rtti::ERTTIType::Class;
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::ClassType::GetComputedName() const
{
    return computedName;
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::Construct(void* aMemory) const
{
    ConstructCls(aMemory);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::Destruct(void* aMemory) const
{
    DestructCls(aMemory);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::Unserialize(BaseStream* aStream, void* aInstance, int64_t a3) const
{
    using func_t = bool (*)(const ClassType*, BaseStream*, void*, int64_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_Unserialize);
    return func(this, aStream, aInstance, a3);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::ToString(const void* aInstance, CString& aOut) const
{
    using func_t = bool (*)(const ClassType*, const void*, CString&);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_ToString);
    return func(this, aInstance, aOut);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::sub_80(int64_t a1, void* aInstance)
{
    using func_t = bool (*)(const ClassType*, int64_t, void*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_80);
    return func(this, a1, aInstance);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::sub_88(int64_t a1, void* aInstance)
{
    using func_t = bool (*)(const ClassType*, int64_t, void*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_88);
    return func(this, a1, aInstance);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::sub_90(int64_t a1, void* aInstance, CString& a3, int64_t a4)
{
    using func_t = bool (*)(const ClassType*, int64_t, void*, CString&, int64_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_90);
    return func(this, a1, aInstance, a3, a4);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::sub_98(int64_t a1, void* aInstance, CString& a3, int64_t a4, bool a5)
{
    RED4EXT_UNUSED_PARAMETER(a5);

    using func_t = bool (*)(const ClassType*, int64_t, void*, CString&, int64_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_90);
    return func(this, a1, aInstance, a3, a4);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::sub_A0(int64_t a1, CString& a2, bool a3)
{
    using func_t = bool (*)(const ClassType*, int64_t, CString&, bool);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_A0);
    return func(this, a1, a2, a3);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::sub_B0(int64_t a1, int64_t a2)
{
    using func_t = bool (*)(const ClassType*, int64_t, int64_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_B0);
    func(this, a1, a2);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::sub_C0()
{
    using func_t = void (*)(ClassType*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_C0);
    func(this);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ClassType::GetMaxAlignment() const
{
    using func_t = uint32_t (*)(const ClassType*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_GetMaxAlignment);
    return func(this);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::sub_D0() const
{
    using func_t = bool (*)(const ClassType*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_D0);
    return func(this);
}

RED4EXT_INLINE void* RED4ext::rtti::ClassType::CreateInstance(bool aZeroMemory) const
{
    using func_t = void* (*)(const ClassType*, uint32_t, bool);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_CreateInstance);
    return func(this, GetSize(), aZeroMemory);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::IsA(const rtti::IType* aType) const
{
    if (this == aType)
    {
        return true;
    }

    if (parent)
    {
        return parent->IsA(aType);
    }

    return false;
}

RED4EXT_INLINE RED4ext::CProperty* RED4ext::rtti::ClassType::GetProperty(CName aName)
{
    // Not recreating this because they do something strage with overriden properties and I am not sure what exactly
    // they do.

    using func_t = CProperty* (*)(ClassType*, CName);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_GetProperty);
    return func(this, aName);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::InitializeProperties(void* aInstance)
{
    static UniversalRelocFunc<void (*)(ClassType*, void*)> initializeProperties(
        Detail::AddressHashes::CClass_InitializeProperties);
    initializeProperties(this, aInstance);

    static UniversalRelocFunc<void (*)(ClassType*, void*)> assignDefaultValuesToProperties(
        Detail::AddressHashes::CClass_AssignDefaultValuesToProperties);
    assignDefaultValuesToProperties(this, aInstance);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::GetProperties(DynArray<CProperty*>& aProps)
{
    using func_t = CProperty* (*)(ClassType*, DynArray<CProperty*>&);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_GetProperties);
    func(this, aProps);
}

RED4EXT_INLINE RED4ext::CClassFunction* RED4ext::rtti::ClassType::GetFunction(CName aShortName) const
{
    for (auto func : staticFuncs)
    {
        if (func->shortName == aShortName)
        {
            return func;
        }
    }

    for (auto func : funcs)
    {
        if (func->shortName == aShortName)
        {
            return func;
        }
    }

    if (parent)
    {
        return parent->GetFunction(aShortName);
    }

    return nullptr;
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::RegisterFunction(CClassFunction* aFunc)
{
    if (aFunc->flags.isStatic)
    {
        staticFuncs.PushBack(static_cast<CClassStaticFunction*>(aFunc));
    }
    else
    {
        funcs.PushBack(aFunc);
    }
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::ClearScriptedData()
{
    using func_t = void (*)(ClassType*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_ClearScriptedData);
    func(this);
}