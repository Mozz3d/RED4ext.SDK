#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/RTTI/BitFieldType.hpp>
#endif

RED4EXT_INLINE RED4ext::rtti::BitFieldType::BitFieldType(CName aName, int8_t aActualSize, Flags aFlags)
    : name(aName)
    , computedName(rtti::IType::GetComputedName())
    , actualSize(aActualSize)
    , flags(aFlags)
    , validBits(0)
{
    std::memset(bitNames, 0, sizeof(bitNames));
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::BitFieldType::GetName() const
{
    return name;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::BitFieldType::GetSize() const
{
    return actualSize;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::BitFieldType::GetAlignment() const
{
    return 1;
}

RED4EXT_INLINE RED4ext::rtti::ERTTIType RED4ext::rtti::BitFieldType::GetType() const
{
    return rtti::ERTTIType::BitField;
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::BitFieldType::GetComputedName() const
{
    return computedName;
}

RED4EXT_INLINE void RED4ext::rtti::BitFieldType::Construct(void* aMemory) const
{
    RED4EXT_UNUSED_PARAMETER(aMemory);
}

RED4EXT_INLINE void RED4ext::rtti::BitFieldType::Destruct(void* aMemory) const
{
    RED4EXT_UNUSED_PARAMETER(aMemory);
}

RED4EXT_INLINE const bool RED4ext::rtti::BitFieldType::IsEqual(const void* aLhs, const void* aRhs, uint32_t a3)
{
    RED4EXT_UNUSED_PARAMETER(a3);

    switch (actualSize)
    {
    case 1:
    {
        return *static_cast<const uint8_t*>(aLhs) == *static_cast<const uint8_t*>(aRhs);
    }
    case 2:
    {
        return *static_cast<const uint16_t*>(aLhs) == *static_cast<const uint16_t*>(aRhs);
    }
    case 4:
    {
        return *static_cast<const uint32_t*>(aLhs) == *static_cast<const uint32_t*>(aRhs);
    }
    case 8:
    {
        return *static_cast<const uint64_t*>(aLhs) == *static_cast<const uint64_t*>(aRhs);
    }
    }

    return false;
}

RED4EXT_INLINE void RED4ext::rtti::BitFieldType::Assign(void* aLhs, const void* aRhs) const
{
    switch (actualSize)
    {
    case 1:
    {
        *static_cast<uint8_t*>(aLhs) = *static_cast<const uint8_t*>(aRhs);
        break;
    }
    case 2:
    {
        *static_cast<uint16_t*>(aLhs) = *static_cast<const uint16_t*>(aRhs);
        break;
    }
    case 4:
    {
        *static_cast<uint32_t*>(aLhs) = *static_cast<const uint32_t*>(aRhs);
        break;
    }
    case 8:
    {
        *static_cast<uint64_t*>(aLhs) = *static_cast<const uint64_t*>(aRhs);
        break;
    }
    }
}

RED4EXT_INLINE bool RED4ext::rtti::BitFieldType::Unserialize(BaseStream* aStream, void* aInstance, int64_t a3) const
{
    using func_t = bool (*)(const BitFieldType*, BaseStream*, void*, int64_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CBitfield_Unserialize);
    return func(this, aStream, aInstance, a3);
}

RED4EXT_INLINE bool RED4ext::rtti::BitFieldType::ToString(const void* aInstance, CString& aOut) const
{
    using func_t = bool (*)(const BitFieldType*, const void*, CString&);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CBitfield_ToString);
    return func(this, aInstance, aOut);
}

RED4EXT_INLINE bool RED4ext::rtti::BitFieldType::FromString(void* aInstance, const CString& aString) const
{
    using func_t = bool (*)(const BitFieldType*, void*, const CString&);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CBitfield_FromString);
    return func(this, aInstance, aString);
}