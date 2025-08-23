#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/RTTI/EnumType.hpp>
#endif

RED4EXT_INLINE RED4ext::rtti::EnumType::EnumType(CName aName, int8_t aActualSize, Flags aFlags)
    : name(aName)
    , computedName(CBaseRTTIType::GetComputedName())
    , actualSize(aActualSize)
    , flags(aFlags)
    , hashList(Memory::RTTIAllocator::Get())
    , valueList(Memory::RTTIAllocator::Get())
    , aliasList(Memory::RTTIAllocator::Get())
    , aliasValueList(Memory::RTTIAllocator::Get())
{
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::EnumType::GetName() const
{
    return name;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::EnumType::GetSize() const
{
    return actualSize;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::EnumType::GetAlignment() const
{
    return 1;
}

RED4EXT_INLINE RED4ext::ERTTIType RED4ext::rtti::EnumType::GetType() const
{
    return ERTTIType::Enum;
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::EnumType::GetRefName() const
{
    return computedName;
}

RED4EXT_INLINE void RED4ext::rtti::EnumType::Construct(ScriptInstance aMemory) const
{
    RED4EXT_UNUSED_PARAMETER(aMemory);
}

RED4EXT_INLINE void RED4ext::rtti::EnumType::Destruct(ScriptInstance aMemory) const
{
    RED4EXT_UNUSED_PARAMETER(aMemory);
}

RED4EXT_INLINE const bool RED4ext::rtti::EnumType::Compare(const ScriptInstance aLhs, const ScriptInstance aRhs, uint32_t a3)
{
    RED4EXT_UNUSED_PARAMETER(a3);

    switch (actualSize)
    {
    case 1:
    {
        return *static_cast<const int8_t*>(aLhs) == *static_cast<const int8_t*>(aRhs);
    }
    case 2:
    {
        return *static_cast<const int16_t*>(aLhs) == *static_cast<const int16_t*>(aRhs);
    }
    case 4:
    {
        return *static_cast<const int32_t*>(aLhs) == *static_cast<const int32_t*>(aRhs);
    }
    case 8:
    {
        return *static_cast<const int64_t*>(aLhs) == *static_cast<const int64_t*>(aRhs);
    }
    }

    return false;
}

RED4EXT_INLINE void RED4ext::rtti::EnumType::Copy(ScriptInstance aLhs, const ScriptInstance aRhs) const
{
    switch (actualSize)
    {
    case 1:
    {
        *static_cast<int8_t*>(aLhs) = *static_cast<const int8_t*>(aRhs);
        break;
    }
    case 2:
    {
        *static_cast<int16_t*>(aLhs) = *static_cast<const int16_t*>(aRhs);
        break;
    }
    case 4:
    {
        *static_cast<int32_t*>(aLhs) = *static_cast<const int32_t*>(aRhs);
        break;
    }
    case 8:
    {
        *static_cast<int64_t*>(aLhs) = *static_cast<const int64_t*>(aRhs);
        break;
    }
    }
}

RED4EXT_INLINE bool RED4ext::rtti::EnumType::Unserialize(BaseStream* aStream, ScriptInstance aInstance, int64_t a3) const
{
    using func_t = bool (*)(const EnumType*, BaseStream*, ScriptInstance, int64_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CEnum_Unserialize);
    return func(this, aStream, aInstance, a3);
}

RED4EXT_INLINE bool RED4ext::rtti::EnumType::ToString(const ScriptInstance aInstance, CString& aOut) const
{
    using func_t = bool (*)(const EnumType*, const ScriptInstance, CString&);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CEnum_ToString);
    return func(this, aInstance, aOut);
}

RED4EXT_INLINE bool RED4ext::rtti::EnumType::FromString(ScriptInstance aInstance, const CString& aString) const
{
    using func_t = bool (*)(const EnumType*, ScriptInstance, const CString&);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CEnum_FromString);
    return func(this, aInstance, aString);
}
