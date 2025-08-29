#pragma once

#include <RED4ext/RTTI/IType.hpp>
#include <RED4ext/Scripting/ArrayAccessors.hpp>

namespace RED4ext
{
using ScriptData = void;
namespace rtti
{
struct IBaseArrayType : IType
{
    virtual bool ToString(const ScriptData* aInstance, CString& aOutString) const final;
    virtual bool SerializeToText(int64_t aWriter, const ScriptData* aData) const final;
    virtual bool SerializeFromText(int64_t aReader, ScriptData* aData) const final;
    virtual bool ReadValue(int64_t aContext, const ScriptData* aData, const CString& aPath, int64_t aOutValue) const final;
    virtual bool WriteValue(int64_t aContext, ScriptData* aData, const CString& aPath, const int64_t aValue, bool a5) const final;
    virtual bool IsPropertyReadOnly(int64_t aContext, const CString& aPath, bool& aOutIsReadyOnly) const final;
    virtual void RebuildParentHierarchy(ScriptData* aData, ISerializable* aParent) const final;

    virtual IType* ArrayGetInnerType() const;                                                            // C0
    virtual bool ArrayIsResizable() const = 0;                                                           // C8
    virtual uint32_t ArrayGetArraySize(const ScriptData* aArray) const = 0;                              // D0
    virtual uint32_t ArrayGetArrayMaxSize(const ScriptData* aArray) const = 0;                           // D8
    virtual const ScriptData* ArrayGetArrayElement(const ScriptData* aArray, uint32_t aIndex) const = 0; // E0
    virtual ScriptData* ArrayGetArrayElement(ScriptData* aArray, uint32_t aIndex) const = 0;             // E8
    virtual int32_t ArrayAddElement(ScriptData* aArray, int32_t aAmount) const = 0;                      // F0
    virtual bool ArrayDeleteElement(ScriptData* aArray, int32_t aIndex) const = 0;                       // F8
    virtual bool ArrayInsertElement(ScriptData* aArray, int32_t aIndex) const = 0;                       // 100
    virtual uint32_t ArrayResize(ScriptData* aArray, uint32_t aSize) const = 0;                          // 108

    // [1, 2, 3]
    // ArrayRTTI->InsertAt(aIndex: 1);
    // [1, (free), 2, 3]
    // InnerRTTI->Assign(ArrayRTTI->GetElement(1), newValue)
    // [1, newValue, 2, 3]

    IType* innerType; // 10
};
RED4EXT_ASSERT_SIZE(IBaseArrayType, 0x18);

struct ArrayType : IBaseArrayType
{
    const red::DynArrayAccessor* GetArrayAccessor(const ScriptData* aArray) const;
    red::DynArrayAccessor* GetArrayAccessor(ScriptData* aArray) const;
    ScriptData* GetArrayData(const ScriptData* aArray) const;
    uint32_t GetArraySize(const ScriptData* aArray) const;
    uint32_t GetArrayMaxSize(const ScriptData* aArray) const;
    const ScriptData* GetArrayElement(const ScriptData* aArray, uint32_t aIndex) const;
    ScriptData* GetArrayElement(ScriptData* aArray, uint32_t aIndex) const;

    int32_t AddArrayElement(ScriptData* aArray, uint32_t aAmount, const Memory::IAllocator& aAllocator) const;
    bool DeleteArrayElement(ScriptData* aArray, int32_t aIndex) const;
    bool InsertArrayElementAt(ScriptData* aArray, int32_t aIndex) const;

    void DestroyArrayElements(ScriptData* aArray) const;

    virtual CName GetName() const final;
    virtual uint32_t GetSize() const final;
    virtual uint32_t GetAlignment() const final;
    virtual ERTTIType GetType() const final;
    virtual void Construct(ScriptData* aMemory) const final;
    virtual void Destruct(ScriptData* aMemory) const final;
    virtual bool Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3 = 0) const final;
    virtual void Copy(ScriptData* aDest, const ScriptData* aSrc) const final;
    virtual void Move(ScriptData* aDest, ScriptData* aSrc) const final;
    virtual bool Serialize(BaseStream* aStream, ScriptData* aData, ISerializable* aDataOwner) const final;

    virtual uint32_t ArrayGetArraySize(const ScriptData* aArray) const final;
    virtual uint32_t ArrayGetArrayMaxSize(const ScriptData* aArray) const final;
    virtual const ScriptData* ArrayGetArrayElement(const ScriptData* aArray, uint32_t aIndex) const final;
    virtual ScriptData* ArrayGetArrayElement(ScriptData* aArray, uint32_t aIndex) const final;
    virtual int32_t ArrayAddElement(ScriptData* aArray, int32_t aAmount) const final;
    virtual bool ArrayDeleteElement(ScriptData* aArray, int32_t aIndex) const final;
    virtual bool ArrayInsertElement(ScriptData* aArray, int32_t aIndex) const final;
    virtual uint32_t ArrayResize(ScriptData* aInstance, uint32_t aSize) const final;

    CName name; // 18
};
RED4EXT_ASSERT_SIZE(ArrayType, 0x20);

struct StaticArrayType : IBaseArrayType
{
    red::StaticArrayAccessor* GetArrayAccessor(const ScriptData* aArray) const;
    ScriptData* GetArrayData(const ScriptData* aArray) const;
    uint32_t GetArraySize(const ScriptData* aArray) const;
    uint32_t GetArrayMaxSize(const ScriptData* aArray) const;
    const ScriptData* GetArrayElement(const ScriptData* aArray, uint32_t aIndex) const;
    ScriptData* GetArrayElement(ScriptData* aArray, uint32_t aIndex) const;

    int32_t AddArrayElement(ScriptData* aArray, uint32_t aAmount) const;
    bool DeleteArrayElement(ScriptData* aArray, int32_t aIndex) const;
    bool InsertArrayElementAt(ScriptData* aArray, int32_t aIndex) const;

    void DestroyArrayElements(ScriptData* aArray) const;

    virtual CName GetName() const final;
    virtual uint32_t GetSize() const final;
    virtual uint32_t GetAlignment() const final;
    virtual ERTTIType GetType() const final;
    virtual CName GetRefName() const final;
    virtual void Construct(ScriptData* aMemory) const final;
    virtual void Destruct(ScriptData* aMemory) const final;
    virtual bool Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3 = 0) const final;
    virtual void Copy(ScriptData* aDest, const ScriptData* aSrc) const final;
    virtual bool Serialize(BaseStream* aStream, ScriptData* aInstanceData, ISerializable* aDataOwner) const final;

    virtual uint32_t ArrayGetArraySize(const ScriptData* aArray) const final;
    virtual uint32_t ArrayGetArrayMaxSize(const ScriptData* aArray) const final;
    virtual const ScriptData* ArrayGetArrayElement(const ScriptData* aArray, uint32_t aIndex) const final;
    virtual ScriptData* ArrayGetArrayElement(ScriptData* aArray, uint32_t aIndex) const final;
    virtual int32_t ArrayAddElement(ScriptData* aArray, int32_t aAmount) const final;
    virtual bool ArrayDeleteElement(ScriptData* aArray, int32_t aIndex) const final;
    virtual bool ArrayInsertElement(ScriptData* aArray, int32_t aIndex) const final;
    virtual uint32_t ArrayResize(ScriptData* aArray, uint32_t aSize) const final;

    uint32_t maxSize;    // 18
    CName name;          // 20
    CName scriptRefName; // 28
};
RED4EXT_ASSERT_SIZE(StaticArrayType, 0x30);

struct NativeArrayType : IBaseArrayType
{
    red::NativeArrayAccessor* GetArrayAccessor(const ScriptData* aArray) const;
    const ScriptData* GetArrayElement(const ScriptData* aArray, uint32_t aIndex) const;
    ScriptData* GetArrayElement(ScriptData* aArray, uint32_t aIndex) const;

    virtual CName GetName() const final;
    virtual uint32_t GetSize() const final;
    virtual uint32_t GetAlignment() const final;
    virtual ERTTIType GetType() const final;
    virtual CName GetRefName() const final;
    virtual void Construct(ScriptData* aMemory) const final;
    virtual void Destruct(ScriptData* aMemory) const final;
    virtual bool Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3 = 0) const final;
    virtual void Copy(ScriptData* aDest, const ScriptData* aSrc) const final;
    virtual bool Serialize(BaseStream* aStream, ScriptData* aInstanceData, ISerializable* aDataOwner) const final;

    virtual bool ArrayIsResizable() const final;
    virtual uint32_t ArrayGetArraySize(const ScriptData* aArray) const final;
    virtual uint32_t ArrayGetArrayMaxSize(const ScriptData* aArray) const final;
    virtual const ScriptData* ArrayGetArrayElement(const ScriptData* aArray, uint32_t aIndex) const final;
    virtual ScriptData* ArrayGetArrayElement(ScriptData* aArray, uint32_t aIndex) const final;
    virtual int32_t ArrayAddElement(ScriptData* aArray, int32_t aAmount) const final;
    virtual bool ArrayDeleteElement(ScriptData* aArray, int32_t aIndex) const final;
    virtual bool ArrayInsertElement(ScriptData* aArray, int32_t aIndex) const final;
    virtual uint32_t ArrayResize(ScriptData* aArray, uint32_t aSize) const final;

    uint32_t size;       // 18
    CName name;          // 20
    CName scriptRefName; // 28
};
RED4EXT_ASSERT_SIZE(NativeArrayType, 0x30);

} // namespace rtti
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/rtti/ArrayType-inl.hpp>
#endif
