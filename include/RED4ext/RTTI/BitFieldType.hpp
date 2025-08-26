#pragma once

#include <RED4ext/RTTI/IType.hpp>

namespace RED4ext
{
namespace rtti
{
struct BitFieldType : IType
{
    struct Flags
    {
        uint8_t isScripted : 1; // 00
        uint8_t b2 : 7;
    };
    RED4EXT_ASSERT_SIZE(BitFieldType::Flags, 0x01);

    BitFieldType(CName aName, int8_t aActualSize, Flags aFlags = {});

    virtual CName GetName() const final;                                                                              // 08
    virtual uint32_t GetSize() const final;                                                                           // 10
    virtual uint32_t GetAlignment() const final;                                                                      // 18
    virtual ERTTIType GetType() const final;                                                                          // 20
    virtual CName GetRefName() const final;                                                                           // 30
    virtual void Construct(ScriptInstance aMemory) const final;                                                       // 38
    virtual void Destruct(ScriptInstance aMemory) const final;                                                        // 40
    virtual const bool Compare(const ScriptInstance aLhs, const ScriptInstance aRhs, uint32_t a3 = 0) final;          // 48
    virtual void Copy(ScriptInstance aDest, const ScriptInstance aSrc) const final;                                   // 50
    virtual bool Serialize(BaseStream* aStream, ScriptInstance aInstanceData, ISerializable* aDataOwner) const final; // 60
    virtual bool ToString(const ScriptInstance aInstance, CString& aOut) const final;                                 // 68
    virtual bool FromString(ScriptInstance aInstance, const CString& aString) const final;                            // 70

    CName name;          // 10
    CName scriptRefName; // 18
    uint8_t actualSize;  // 20
    Flags flags;         // 21
    uint64_t validBits;  // 28
    CName bitNames[64];  // 30
};
RED4EXT_ASSERT_SIZE(BitFieldType, 0x230);
RED4EXT_ASSERT_OFFSET(BitFieldType, name, 0x10);
RED4EXT_ASSERT_OFFSET(BitFieldType, scriptRefName, 0x18);
RED4EXT_ASSERT_OFFSET(BitFieldType, actualSize, 0x20);
RED4EXT_ASSERT_OFFSET(BitFieldType, flags, 0x21);
RED4EXT_ASSERT_OFFSET(BitFieldType, validBits, 0x28);
RED4EXT_ASSERT_OFFSET(BitFieldType, bitNames, 0x30);

} // namespace rtti
struct [[deprecated("Use 'rtti::BitFieldType' instead.")]] CBitfield : rtti::BitFieldType
{
};
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/RTTI/BitFieldType-inl.hpp>
#endif
