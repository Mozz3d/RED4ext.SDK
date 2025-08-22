#pragma once

#include <RED4ext/CName.hpp>
#include <RED4ext/CString.hpp>

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

    virtual CName GetName() const = 0;                                                                     // 08
    virtual uint32_t GetSize() const = 0;                                                                  // 10
    virtual uint32_t GetAlignment() const = 0;                                                             // 18
    virtual ERTTIType GetType() const = 0;                                                                 // 20
    virtual CString GetERTTITypeString() const;                                                            // 28
    virtual CName GetRefName() const;                                                                      // 30
    virtual void Construct(ScriptInstance aMemory) const = 0;                                              // 38
    virtual void Destruct(ScriptInstance aMemory) const = 0;                                               // 40
    virtual bool Compare(const ScriptInstance aLhs, const ScriptInstance aRhs, uint32_t a3 = 0) const = 0; // 48 
    virtual void Copy(ScriptInstance aLhs, const ScriptInstance aRhs) const = 0;                           // 50
    virtual void Move(ScriptInstance aLhs, ScriptInstance aRhs) const;                                     // 58
    virtual bool Unserialize(BaseStream* aStream, ScriptInstance aInstance, int64_t a3) const = 0;         // 60
    virtual bool ToString(const ScriptInstance aInstance, CString& aOut) const;                            // 68
    virtual bool FromString(ScriptInstance aInstance, const CString& aString) const;                       // 70
    virtual bool sub_78();                                                                                 // 78
    virtual bool SerializeToText(int64_t a1, ScriptInstance aInstance);                                    // 80
    virtual bool SerializeFromText(int64_t a1, ScriptInstance aInstance);                                  // 88
    virtual bool ReadValue(int64_t a1, ScriptInstance aInstance, CString& a3, int64_t a4);                 // 90
    virtual bool WriteValue(int64_t a1, ScriptInstance aInstance, CString& a3, int64_t a4, bool a5);       // 98
    virtual bool IsPropertyReadOnly(int64_t a1, CString& a2, bool a3);                                     // A0
    virtual bool IsTriviallyMovable();                                                                     // A8
    virtual void RebuildParentHierarchy(int64_t a1, int64_t a2);                                           // B0
    virtual Memory::IAllocator* GetAllocator() const;                                                      // B8

    void* unk8;
};
RED4EXT_ASSERT_SIZE(IType, 0x10);
}
using ERTTIType = rtti::ERTTIType;
}
