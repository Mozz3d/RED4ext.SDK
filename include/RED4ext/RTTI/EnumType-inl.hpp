#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/RTTI/EnumType.hpp>
#endif

RED4EXT_INLINE RED4ext::rtti::EnumType::EnumType(CName aName, int8_t aActualSize, Flags aFlags)
    : name(aName)
    , scriptRefName(IType::GetRefName())
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
    return scriptRefName;
}

RED4EXT_INLINE void RED4ext::rtti::EnumType::Construct(ScriptData* aMemory) const
{
    RED4EXT_UNUSED_PARAMETER(aMemory);
}

RED4EXT_INLINE void RED4ext::rtti::EnumType::Destruct(ScriptData* aMemory) const
{
    RED4EXT_UNUSED_PARAMETER(aMemory);
}

RED4EXT_INLINE const bool RED4ext::rtti::EnumType::Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3)
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

RED4EXT_INLINE void RED4ext::rtti::EnumType::Copy(ScriptData* aDest, const ScriptData* aSrc) const
{
    switch (actualSize)
    {
    case 1:
    {
        *static_cast<int8_t*>(aDest) = *static_cast<const int8_t*>(aSrc);
        break;
    }
    case 2:
    {
        *static_cast<int16_t*>(aDest) = *static_cast<const int16_t*>(aSrc);
        break;
    }
    case 4:
    {
        *static_cast<int32_t*>(aDest) = *static_cast<const int32_t*>(aSrc);
        break;
    }
    case 8:
    {
        *static_cast<int64_t*>(aDest) = *static_cast<const int64_t*>(aSrc);
        break;
    }
    }
}

RED4EXT_INLINE bool RED4ext::rtti::EnumType::Serialize(BaseStream* aStream, ScriptData* aData, ISerializable* aDataOwner) const
{
    using func_t = bool (*)(const EnumType*, BaseStream*, void*, ISerializable*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CEnum_Unserialize);
    return func(this, aStream, aData, aDataOwner);
}

RED4EXT_INLINE bool RED4ext::rtti::EnumType::ToString(const ScriptData* aObject, CString& aOut) const
{
    using func_t = bool (*)(const EnumType*, const void*, CString&);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CEnum_ToString);
    return func(this, aObject, aOut);
}

RED4EXT_INLINE bool RED4ext::rtti::EnumType::FromString(ScriptData* aObject, const CString& aString) const
{
    using func_t = bool (*)(const EnumType*, void*, const CString&);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CEnum_FromString);
    return func(this, aObject, aString);
}
