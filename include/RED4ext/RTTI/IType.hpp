#pragma once

#include <RED4ext/CName.hpp>
#include <RED4ext/CString.hpp>
#include <RED4ext/InstanceType.hpp>
#include <RED4ext/IO/BaseStream.hpp>

namespace RED4ext
{
namespace rtti
{
enum class ERTTIType : uint8_t
{
    Name = 0,
    Fundamental = 1,
    Class = 2,
    Array = 3,
    Simple = 4,
    Enum = 5,
    StaticArray = 6,
    NativeArray = 7,
    Pointer = 8,
    Handle = 9,
    WeakHandle = 10,
    ResourceReference = 11,
    ResourceAsyncReference = 12,
    BitField = 13,
    LegacySingleChannelCurve = 14,
    ScriptReference = 15,
    FixedArray = 16
};

struct IType
{
    IType();
    virtual ~IType() = default; // 00

    virtual CName GetName() const = 0;                                                                                       // 08
    virtual uint32_t GetSize() const = 0;                                                                                    // 10
    virtual uint32_t GetAlignment() const = 0;                                                                               // 18
    virtual ERTTIType GetType() const = 0;                                                                                   // 20
    virtual CString GetERTTITypeString() const;                                                                              // 28
    virtual CName GetRefName() const;                                                                                        // 30
    virtual void Construct(ScriptData* aMemory) const = 0;                                                                   // 38
    virtual void Destruct(ScriptData* aMemory) const = 0;                                                                    // 40
    virtual bool Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3 = 0) const = 0;                         // 48 
    virtual void Copy(ScriptData* aDest, const ScriptData* aSrc) const = 0;                                                  // 50
    virtual void Move(ScriptData* aDest, ScriptData* aSrc) const;                                                            // 58
    virtual bool Serialize(BaseStream* aStream, ScriptData* aData, ISerializable* aDataOwner) const = 0;                     // 60
    virtual bool ToString(const ScriptData* aObject, CString& aOutString) const;                                             // 68
    virtual bool FromString(ScriptData* aObject, const CString& aString) const;                                              // 70
    virtual bool sub_78();                                                                                                   // 78
    virtual bool SerializeToText(int64_t aWriter, const ScriptData* aData) const;                                            // 80
    virtual bool SerializeFromText(int64_t aReader, ScriptData* aData) const;                                                // 88
    virtual bool ReadValue(int64_t aContext, const ScriptData* aData, const CString& aPath, int64_t aOutValue) const;        // 90
    virtual bool WriteValue(int64_t aContext, ScriptData* aData, const CString& aPath, const int64_t aValue, bool a5) const; // 98
    virtual bool IsPropertyReadOnly(int64_t aContext, const CString& aPath, bool& aOutIsReadyOnly) const;                    // A0
    virtual bool IsTriviallyMovable();                                                                                       // A8
    virtual void RebuildParentHierarchy(ScriptData* aObject, ISerializable* aParent) const;                                  // B0
    virtual Memory::IAllocator* GetAllocator() const;                                                                        // B8

#pragma region deprecated
    [[deprecated("Use 'GetERTTITypeString' instead.")]]
    RED4EXT_INLINE CString GetTypeName() const
    {
        return GetERTTITypeString();
    }

    [[deprecated("Use 'GetRefName' instead.")]]
    RED4EXT_INLINE CName GetComputedName() const
    {
        return GetRefName();
    }

    [[deprecated("Use 'Compare' instead.")]]
    RED4EXT_INLINE bool IsEqual(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3 = 0) const
    {
        return Compare(aLhs, aRhs, a3);
    }

    [[deprecated("Use 'Copy' instead.")]]
    RED4EXT_INLINE void Assign(ScriptData* aDest, const ScriptData* aSrc) const
    {
        Copy(aDest, aSrc);
    }
#pragma endregion

    void* unk8;
};
RED4EXT_ASSERT_SIZE(IType, 0x10);
}
using ERTTIType = rtti::ERTTIType;

struct [[deprecated("Use 'rtti::IType' instead.")]] CBaseRTTIType : rtti::IType
{
};
}

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/rtti/IType-inl.hpp>
#endif
