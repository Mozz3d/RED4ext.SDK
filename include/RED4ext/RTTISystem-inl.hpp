#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/RTTISystem.hpp>
#endif

#include <RED4ext/Detail/AddressHashes.hpp>
#include <RED4ext/Relocation.hpp>

RED4EXT_INLINE RED4ext::rtti::TypeSystemImpl* RED4ext::rtti::TypeSystemImpl::Get()
{
    static UniversalRelocFunc<TypeSystemImpl* (*)()> func(Detail::AddressHashes::CRTTISystem_Get);
    return func();
}

RED4EXT_INLINE void RED4ext::rtti::TypeSystemImpl::RegisterType(IType* aType)
{
    RegisterType(aType, RTTIRegistrator::GetNextId());
}

RED4EXT_INLINE void RED4ext::rtti::RTTIRegistrator::Add(CallbackFunc aRegFunc, CallbackFunc aPostRegFunc, bool aUnused)
{
    RED4EXT_UNUSED_PARAMETER(aUnused);

    if (aRegFunc)
    {
        TypeSystemImpl::Get()->AddRegisterCallback(aRegFunc);
    }

    if (aPostRegFunc)
    {
        TypeSystemImpl::Get()->AddPostRegisterCallback(aPostRegFunc);
    }
}

RED4EXT_INLINE const uint32_t RED4ext::rtti::RTTIRegistrator::GetNextId()
{
    static UniversalRelocPtr<volatile uint32_t> ptr(Detail::AddressHashes::CRTTIRegistrator_RTTIAsyncId);
    return InterlockedIncrement(ptr.GetAddr());
}
