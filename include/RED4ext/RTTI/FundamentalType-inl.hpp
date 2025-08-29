#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/RTTI/FundamentalType.hpp>
#endif

template<typename T>
RED4EXT_INLINE RED4ext::CName RED4ext::rtti::IFundamentalType<T>::GetName() const
{
    if constexpr (Detail::AddressHashes::FundamentalType<T>::GetName)
    {
        using func_t = CName(*)(const IFundamentalType<T>*);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::FundamentalType<T>::GetName);
        return func(this);
    }
}

template<typename T>
RED4EXT_INLINE RED4ext::CName RED4ext::rtti::IFundamentalType<T>::GetRefName() const
{
    if constexpr (Detail::AddressHashes::FundamentalType<T>::GetRefName)
    {
        using func_t = CName(*)(const IFundamentalType<T>*);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::FundamentalType<T>::GetRefName);
        return func(this);
    }
}

template<typename T>
RED4EXT_INLINE bool RED4ext::rtti::IFundamentalType<T>::Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3) const
{
    return *static_cast<const T*>(aLhs) == *static_cast<const T*>(aRhs);
}

template<typename T>
RED4EXT_INLINE void RED4ext::rtti::IFundamentalType<T>::Copy(ScriptData* aDest, const ScriptData* aSrc) const
{
    *static_cast<T*>(aDest) = *static_cast<const T*>(aSrc);
}

template<typename T>
RED4EXT_INLINE bool RED4ext::rtti::IFundamentalType<T>::Serialize(BaseStream* aStream, ScriptData* aData, ISerializable* aDataOwner) const
{
    aStream->ReadWrite(aData, sizeof(T));
    return true;
}

template<typename T>
RED4EXT_INLINE bool RED4ext::rtti::IFundamentalType<T>::ToString(const ScriptData* aObject, CString& aOutString) const
{
    if constexpr (Detail::AddressHashes::FundamentalType<T>::ToString)
    {
        using func_t = bool(*)(const IFundamentalType<T>*, const void*, CString&);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::FundamentalType<T>::ToString);
        return func(this, aObject, aOutString);
    }
}

template<typename T>
RED4EXT_INLINE bool RED4ext::rtti::IFundamentalType<T>::FromString(ScriptData* aObject, const CString& aString) const
{
    if constexpr (Detail::AddressHashes::FundamentalType<T>::FromString)
    {
        using func_t = bool(*)(const IFundamentalType<T>*, void*, const CString&);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::FundamentalType<T>::FromString);
        return func(this, aObject, aString);
    }
}

template<typename T>
RED4EXT_INLINE bool RED4ext::rtti::IFundamentalType<T>::ReadValue(int64_t aContext, const ScriptData* aData, const CString& aPath, int64_t aOutValue) const
{
    if constexpr (Detail::AddressHashes::FundamentalType<T>::ReadValue)
    {
        using func_t = bool(*)(const IFundamentalType<T>*, int64_t, const void*, const CString&, int64_t);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::FundamentalType<T>::ReadValue);
        return func(this, aContext, aData, aPath, aOutValue);
    }
}

template<typename T>
RED4EXT_INLINE bool RED4ext::rtti::IFundamentalType<T>::WriteValue(int64_t aContext, ScriptData* aData, const CString& aPath, const int64_t aOutValue, bool a5) const
{
    if constexpr (Detail::AddressHashes::FundamentalType<T>::WriteValue)
    {
        using func_t = bool(*)(const IFundamentalType<T>*, int64_t, void*, const CString&, const int64_t, bool);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::FundamentalType<T>::WriteValue);
        return func(this, aContext, aData, aPath, aOutValue, a5);
    }
}
