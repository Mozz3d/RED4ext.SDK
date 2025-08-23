#pragma once

#include <RED4ext/RTTI/IType.hpp>

namespace RED4ext
{
namespace rtti
{
struct EnumType : IType
{
    struct Flags
    {
        uint8_t isScripted : 1; // 00
        uint8_t b2 : 7;
    };
    RED4EXT_ASSERT_SIZE(CEnum::Flags, 0x01);

    CEnum(CName aName, int8_t aActualSize, Flags aFlags = {});

    virtual CName GetName() const final;                                                                     // 08
    virtual uint32_t GetSize() const final;                                                                  // 10
    virtual uint32_t GetAlignment() const final;                                                             // 18
    virtual ERTTIType GetType() const final;                                                                 // 20
    virtual CName GetRefName() const final;                                                                  // 30
    virtual void Construct(ScriptInstance aMemory) const final;                                              // 38
    virtual void Destruct(ScriptInstance aMemory) const final;                                               // 40
    virtual const bool Compare(const ScriptInstance aLhs, const ScriptInstance aRhs, uint32_t a3 = 0) final; // 48
    virtual void Copy(ScriptInstance aLhs, const ScriptInstance aRhs) const final;                           // 50
    virtual bool Unserialize(BaseStream* aStream, ScriptInstance aInstance, int64_t a3) const final;         // 60
    virtual bool ToString(const ScriptInstance aInstance, CString& aOut) const final;                        // 68
    virtual bool FromString(ScriptInstance aInstance, const CString& aString) const final;                   // 70

    CName name;                       // 10
    CName scriptRefName;              // 18
    uint8_t actualSize;               // 20
    Flags flags;                      // 21
    DynArray<CName> hashList;         // 28
    DynArray<int64_t> valueList;      // 38
    DynArray<CName> aliasList;        // 48
    DynArray<int64_t> aliasValueList; // 58
};
RED4EXT_ASSERT_SIZE(EnumType, 0x68);
RED4EXT_ASSERT_OFFSET(EnumType, name, 0x10);
RED4EXT_ASSERT_OFFSET(EnumType, scriptRefName, 0x18);
RED4EXT_ASSERT_OFFSET(EnumType, actualSize, 0x20);
RED4EXT_ASSERT_OFFSET(EnumType, flags, 0x21);
RED4EXT_ASSERT_OFFSET(EnumType, hashList, 0x28);
RED4EXT_ASSERT_OFFSET(EnumType, valueList, 0x38);
RED4EXT_ASSERT_OFFSET(EnumType, aliasList, 0x48);
RED4EXT_ASSERT_OFFSET(EnumType, aliasValueList, 0x58);

} // namespace rtti

} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/RTTI/EnumType-inl.hpp>
#endif
