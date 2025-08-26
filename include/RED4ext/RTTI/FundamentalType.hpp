#pragma once

#include <RED4ext/RTTI/IType.hpp>

namespace RED4ext
{
namespace rtti
{

template<typename T>
struct IFundamentalType : IType
{
    virtual CName GetName() const final; // actually belongs to derived class but is here for simplicity
    virtual ERTTIType GetType() const final { return ERTTIType::Fundamental; }
    virtual uint32_t GetSize() const final { sizeof(T); }
    virtual uint32_t GetAlignment() const final { __alignof(T); }
    virtual CName GetRefName() const final; // actually belongs to derived class but is here for simplicity
    virtual void Construct(ScriptInstance aMemory) const final { return; }
    virtual void Destruct(ScriptInstance aMemory) const final { return; }
    virtual bool Compare(const ScriptInstance aLhs, const ScriptInstance aRhs, uint32_t a3 = 0) const final;
    virtual void Copy(ScriptInstance aDest, const ScriptInstance aSrc) const final;
    virtual bool Serialize(BaseStream* aStream, ScriptInstance aInstanceData, ISerializable* aDataOwner) const final;
    virtual bool ToString(const ScriptInstance aInstance, CString& aOutString) const final;
    virtual bool FromString(ScriptInstance aInstance, const CString& aString) const final;
    virtual bool ReadValue(int64_t aContext, const ScriptInstance aInstance, const CString& aPath, int64_t aOutValue) const final;
    virtual bool WriteValue(int64_t aContext, ScriptInstance aInstance, const CString& aPath, const int64_t aOutValue, bool a5) const final;
};

struct FundamentalTypeBool : IFundamentalType<bool>
{
};

struct FundamentalTypeInt8 : IFundamentalType<int8_t>
{
};

struct FundamentalTypeUint8 : IFundamentalType<uint8_t>
{
};

struct FundamentalTypeInt16 : IFundamentalType<int16_t>
{
};

struct FundamentalTypeUint16 : IFundamentalType<uint16_t>
{
};

struct FundamentalTypeInt32 : IFundamentalType<int32_t>
{
};

struct FundamentalTypeUint32 : IFundamentalType<uint32_t>
{
};

struct FundamentalTypeFloat : IFundamentalType<float>
{
};

struct FundamentalTypeDouble : IFundamentalType<double>
{
};

struct FundamentalTypeInt64 : IFundamentalType<int64_t>
{
};

struct FundamentalTypeUint64 : IFundamentalType<uint64_t>
{
};

} // namespace rtti

#pragma region deprecated
using CFundamentalRTTITypeBool [[deprecated("Use 'rtti::FundamentalTypeBool' instead.")]] = rtti::FundamentalTypeBool;
using CFundamentalRTTITypeInt8 [[deprecated("Use 'rtti::FundamentalTypeInt8' instead.")]] = rtti::FundamentalTypeInt8;
using CFundamentalRTTITypeUint8 [[deprecated("Use 'rtti::FundamentalTypeUint8' instead.")]] = rtti::FundamentalTypeUint8;;
using CFundamentalRTTITypeInt16 [[deprecated("Use 'rtti::FundamentalTypeInt16' instead.")]] = rtti::FundamentalTypeInt16;
using CFundamentalRTTITypeUint16 [[deprecated("Use 'rtti::FundamentalTypeUint16' instead.")]] = rtti::FundamentalTypeUint16;
using CFundamentalRTTITypeInt32 [[deprecated("Use 'rtti::FundamentalTypeInt32' instead.")]] = rtti::FundamentalTypeInt32;
using CFundamentalRTTITypeUint32 [[deprecated("Use 'rtti::FundamentalTypeUint32' instead.")]] = rtti::FundamentalTypeUint32;
using CFundamentalRTTITypeInt64 [[deprecated("Use 'rtti::FundamentalTypeInt64' instead.")]] = rtti::FundamentalTypeInt64;
using CFundamentalRTTITypeUint64 [[deprecated("Use 'rtti::FundamentalTypeUint64' instead.")]] = rtti::FundamentalTypeUint64;
using CFundamentalRTTITypeFloat [[deprecated("Use 'rtti::FundamentalTypeFloat' instead.")]] = rtti::FundamentalTypeFloat;
using CFundamentalRTTITypeDouble [[deprecated("Use 'rtti::FundamentalTypeDouble' instead.")]] = rtti::FundamentalTypeDouble;
#pragma endregion

} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/rtti/FundamentalType-inl.hpp>
#endif
