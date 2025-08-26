#pragma once

#include <RED4ext/CName.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/InstanceType.hpp>
#include <RED4ext/RTTI/NativeClass.hpp>
#include <RED4ext/RTTI/EnumType.hpp>
#include <RED4ext/RTTI/BitFieldType.hpp>
#include <RED4ext/RTTI/FundamentalType.hpp>

#include <type_traits>

namespace RED4ext
{
struct BaseStream;
struct Variant;

#pragma region Simples
using CSimpleRTTITypeCName = CBaseRTTIType;
using CSimpleRTTITypeString = CBaseRTTIType;
using CSimpleRTTITypeLocalizationString = CBaseRTTIType;
using CSimpleRTTITypeTweakDBID = CBaseRTTIType;
using CSimpleRTTITypeDataBuffer = CBaseRTTIType;
using CSimpleRTTITypeSerializationDeferredDataBuffer = CBaseRTTIType;
using CSimpleRTTITypeSharedDataBuffer = CBaseRTTIType;
using CSimpleRTTITypeVariant = CBaseRTTIType;
using CSimpleRTTITypeCDateTime = CBaseRTTIType;
using CSimpleRTTITypeCGUID = CBaseRTTIType;
using CSimpleRTTITypeCRUID = CBaseRTTIType;
using CSimpleRTTITypeCRUIDRef = CBaseRTTIType;
using CSimpleRTTITypeEditorObjectID = CBaseRTTIType;
using CSimpleRTTITypeGamedataLocKeyWrapper = CBaseRTTIType;
using CSimpleRTTITypeMessageResourcePath = CBaseRTTIType;
using CSimpleRTTITypeNodeRef = CBaseRTTIType;
using CSimpleRTTITypeRuntimeEntityRef = CBaseRTTIType;
#pragma endregion

#pragma region Arrays
struct CRTTIBaseArrayType : CBaseRTTIType
{
    virtual CBaseRTTIType* GetInnerType() const = 0;                                        // C0
    virtual bool sub_C8() = 0;                                                              // C8 ret 1
    virtual uint32_t GetLength(ScriptInstance aInstance) const = 0;                         // D0
    virtual int32_t GetMaxLength() const = 0;                                               // D8 ret -1
    virtual ScriptInstance GetElement(ScriptInstance aInstance, uint32_t aIndex) const = 0; // E0
    virtual ScriptInstance sub_E8(ScriptInstance aInstance, uint32_t aIndex) const = 0;     // E8 Same as E0
    virtual int32_t Add(ScriptInstance aInstance, int32_t aCount) const = 0;                // F0
    virtual bool RemoveAt(ScriptInstance aInstance, int32_t aIndex) const = 0;              // F8
    // [1, 2, 3]
    // ArrayRTTI->InsertAt(aIndex: 1);
    // [1, (free), 2, 3]
    // InnerRTTI->Assign(ArrayRTTI->GetElement(1), newValue)
    // [1, newValue, 2, 3]
    virtual bool InsertAt(ScriptInstance aInstance, int32_t aIndex) const = 0; // 100
    virtual bool Resize(ScriptInstance aInstance, uint32_t aSize) const = 0;   // 108

    CBaseRTTIType* innerType; // 10
};
RED4EXT_ASSERT_SIZE(CRTTIBaseArrayType, 0x18);
RED4EXT_ASSERT_OFFSET(CRTTIBaseArrayType, innerType, 0x10);

struct CRTTIArrayType : CRTTIBaseArrayType
{
    CName name;            // 18
    CBaseRTTIType* parent; // 20
    uintptr_t unk28;       // 28
    uintptr_t unk30;       // 30
    uintptr_t unk38;       // 38
};
RED4EXT_ASSERT_SIZE(CRTTIArrayType, 0x40);
RED4EXT_ASSERT_OFFSET(CRTTIArrayType, parent, 0x20);

struct CRTTIStaticArrayType : CRTTIBaseArrayType
{
    int32_t size;       // 18
    uint32_t pad1C;     // 1C
    CName name;         // 20
    CName computedName; // 28
};
RED4EXT_ASSERT_SIZE(CRTTIStaticArrayType, 0x30);
RED4EXT_ASSERT_OFFSET(CRTTIStaticArrayType, size, 0x18);
RED4EXT_ASSERT_OFFSET(CRTTIStaticArrayType, name, 0x20);
RED4EXT_ASSERT_OFFSET(CRTTIStaticArrayType, computedName, 0x28);

struct CRTTINativeArrayType : CRTTIBaseArrayType
{
    int32_t size;       // 18
    uint32_t pad1C;     // 1C
    CName name;         // 20
    CName computedName; // 28
};
RED4EXT_ASSERT_SIZE(CRTTINativeArrayType, 0x30);
RED4EXT_ASSERT_OFFSET(CRTTINativeArrayType, size, 0x18);
RED4EXT_ASSERT_OFFSET(CRTTINativeArrayType, name, 0x20);
RED4EXT_ASSERT_OFFSET(CRTTINativeArrayType, computedName, 0x28);
#pragma endregion

struct CRTTIPointerType : CBaseRTTIType
{
    CBaseRTTIType* innerType; // 10
    CName name;               // 18
    CName unk20;              // 20
};
RED4EXT_ASSERT_SIZE(CRTTIPointerType, 0x28);
RED4EXT_ASSERT_OFFSET(CRTTIPointerType, innerType, 0x10);
RED4EXT_ASSERT_OFFSET(CRTTIPointerType, name, 0x18);
RED4EXT_ASSERT_OFFSET(CRTTIPointerType, unk20, 0x20);

struct CRTTIScriptReferenceType : CBaseRTTIType
{
    // No need for a destructor as it doesn't do anything
    static CRTTIScriptReferenceType* New(void* aMemory, void* aUnknownArg = nullptr)
    {
        using func_t = void (*)(void*, void*);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CRTTIScriptReferenceType_ctor);
        func(aMemory, aUnknownArg);

        return (CRTTIScriptReferenceType*)aMemory;
    }

    template<class T>
    void Set(CBaseRTTIType* aBaseType, const T* aValue)
    {
        using func_t = void (*)(CRTTIScriptReferenceType*, CBaseRTTIType*, const T*);
        static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CRTTIScriptReferenceType_Set);
        func(this, aBaseType, aValue);
    }

    CBaseRTTIType* innerType; // 10
    int64_t unk18;            // 18
    CName name;               // 20
};
RED4EXT_ASSERT_SIZE(CRTTIScriptReferenceType, 0x28);
RED4EXT_ASSERT_OFFSET(CRTTIScriptReferenceType, innerType, 0x10);
RED4EXT_ASSERT_OFFSET(CRTTIScriptReferenceType, unk18, 0x18);
RED4EXT_ASSERT_OFFSET(CRTTIScriptReferenceType, name, 0x20);

struct CRTTIHandleType : CBaseRTTIType
{
    virtual CBaseRTTIType* GetInnerType() const = 0;   // C0
    virtual void sub_C8(void* aUnk1, void* aUnk2) = 0; // C8
    virtual void sub_D0(void* aUnk1, void* aUnk2) = 0; // D0
    virtual void sub_D8(void* aUnk1, void* aUnk2) = 0; // D8

    CBaseRTTIType* innerType; // 10
    CName name;               // 18
    CName computedName;       // 20
};
RED4EXT_ASSERT_SIZE(CRTTIHandleType, 0x28);
RED4EXT_ASSERT_OFFSET(CRTTIHandleType, innerType, 0x10);
RED4EXT_ASSERT_OFFSET(CRTTIHandleType, name, 0x18);
RED4EXT_ASSERT_OFFSET(CRTTIHandleType, computedName, 0x20);

struct CRTTIWeakHandleType : CBaseRTTIType
{
    virtual CBaseRTTIType* GetInnerType() const = 0;   // C0
    virtual void sub_C8(void* aUnk1, void* aUnk2) = 0; // C8
    virtual void sub_D0(void* aUnk1, void* aUnk2) = 0; // D0
    virtual void sub_D8(void* aUnk1, void* aUnk2) = 0; // D8 - Empty impl

    CBaseRTTIType* innerType; // 10
    CName name;               // 18
    CName computedName;       // 20
};
RED4EXT_ASSERT_SIZE(CRTTIWeakHandleType, 0x28);
RED4EXT_ASSERT_OFFSET(CRTTIWeakHandleType, innerType, 0x10);
RED4EXT_ASSERT_OFFSET(CRTTIWeakHandleType, name, 0x18);
RED4EXT_ASSERT_OFFSET(CRTTIWeakHandleType, computedName, 0x20);

struct CRTTIResourceReferenceType : CBaseRTTIType
{
    CName name;               // 10
    CName computedName;       // 18
    CBaseRTTIType* innerType; // 20
};
RED4EXT_ASSERT_SIZE(CRTTIResourceReferenceType, 0x28);
RED4EXT_ASSERT_OFFSET(CRTTIResourceReferenceType, name, 0x10);
RED4EXT_ASSERT_OFFSET(CRTTIResourceReferenceType, computedName, 0x18);
RED4EXT_ASSERT_OFFSET(CRTTIResourceReferenceType, innerType, 0x20);

struct CRTTIResourceAsyncReferenceType : CBaseRTTIType
{
    CName name;               // 10
    CName computedName;       // 18
    CBaseRTTIType* innerType; // 20
};
RED4EXT_ASSERT_SIZE(CRTTIResourceAsyncReferenceType, 0x28);
RED4EXT_ASSERT_OFFSET(CRTTIResourceAsyncReferenceType, name, 0x10);
RED4EXT_ASSERT_OFFSET(CRTTIResourceAsyncReferenceType, computedName, 0x18);
RED4EXT_ASSERT_OFFSET(CRTTIResourceAsyncReferenceType, innerType, 0x20);

struct CRTTILegacySingleChannelCurveType : CBaseRTTIType
{
    CName name;               // 10
    uint64_t unk18;           // 18
    uint64_t unk20;           // 20
    uint64_t unk28;           // 28
    uint8_t unk30;            // 30
    uint8_t unk31;            // 31
    uint16_t pad32;           // 32
    uint32_t pad34;           // 34
    CBaseRTTIType* curveType; // 38
    uint16_t unk40;           // 40
    uint16_t pad42;           // 42
    uint32_t pad44;           // 44
};
RED4EXT_ASSERT_SIZE(CRTTILegacySingleChannelCurveType, 0x48);
RED4EXT_ASSERT_OFFSET(CRTTILegacySingleChannelCurveType, name, 0x10);
RED4EXT_ASSERT_OFFSET(CRTTILegacySingleChannelCurveType, curveType, 0x38);

struct CRTTIMultiChannelCurveType : CBaseRTTIType
{
    CName name;               // 10
    CBaseRTTIType* curveType; // 18
    int64_t unk20;            // 20
    int64_t unk28;            // 28
    int64_t unk30;            // 30
    int64_t unk38;            // 38
    int32_t unk40;            // 40
    int16_t unk44;            // 44
};
RED4EXT_ASSERT_SIZE(CRTTIMultiChannelCurveType, 0x48);
RED4EXT_ASSERT_OFFSET(CRTTIMultiChannelCurveType, name, 0x10);
RED4EXT_ASSERT_OFFSET(CRTTIMultiChannelCurveType, curveType, 0x18);

struct [[deprecated("Use 'CBaseRTTIType' instead.")]] IRTTIType : CBaseRTTIType
{
};
struct [[deprecated("Use 'CBaseRTTIType' instead.")]] CRTTIBaseType : CBaseRTTIType
{
};
struct [[deprecated("Use 'CBaseRTTIType' instead.")]] CRTTIType : CBaseRTTIType
{
};

struct [[deprecated("Use 'CFundamentalRTTITypeBool' instead.")]] BoolType : CFundamentalRTTITypeBool
{
};
struct [[deprecated("Use 'CFundamentalRTTITypeInt8' instead.")]] Int8Type : CFundamentalRTTITypeInt8
{
};
struct [[deprecated("Use 'CFundamentalRTTITypeUint8' instead.")]] Uint8Type : CFundamentalRTTITypeUint8
{
};
struct [[deprecated("Use 'CFundamentalRTTITypeInt16' instead.")]] Int16Type : CFundamentalRTTITypeInt16
{
};
struct [[deprecated("Use 'CFundamentalRTTITypeUint16' instead.")]] Uint16Type : CFundamentalRTTITypeUint16
{
};
struct [[deprecated("Use 'CFundamentalRTTITypeInt32' instead.")]] Int32Type : CFundamentalRTTITypeInt32
{
};
struct [[deprecated("Use 'CFundamentalRTTITypeUint32' instead.")]] Uint32Type : CFundamentalRTTITypeUint32
{
};
struct [[deprecated("Use 'CFundamentalRTTITypeInt64' instead.")]] Int64Type : CFundamentalRTTITypeInt64
{
};
struct [[deprecated("Use 'CFundamentalRTTITypeUint64' instead.")]] Uint64Type : CFundamentalRTTITypeUint64
{
};
struct [[deprecated("Use 'CFundamentalRTTITypeFloat' instead.")]] FloatType : CFundamentalRTTITypeFloat
{
};
struct [[deprecated("Use 'CFundamentalRTTITypeDouble' instead.")]] DoubleType : CFundamentalRTTITypeDouble
{
};

struct [[deprecated("Use 'CSimpleRTTITypeCName' instead.")]] CNameType : CSimpleRTTITypeCName
{
};
struct [[deprecated("Use 'CSimpleRTTITypeString' instead.")]] StringType : CSimpleRTTITypeString
{
};
struct [[deprecated("Use 'CSimpleRTTITypeLocalizationString' instead.")]] LocalizationStringType
    : CSimpleRTTITypeLocalizationString
{
};
struct [[deprecated("Use 'CSimpleRTTITypeTweakDBID' instead.")]] TweakDBIDType : CSimpleRTTITypeTweakDBID
{
};
struct [[deprecated("Use 'CSimpleRTTITypeDataBuffer' instead.")]] DataBufferType : CSimpleRTTITypeDataBuffer
{
};
struct [[deprecated("Use 'CSimpleRTTITypeSharedDataBuffer' instead.")]] SharedDataBufferType
    : CSimpleRTTITypeSharedDataBuffer
{
};
struct [[deprecated(
    "Use 'CSimpleRTTITypeSerializationDeferredDataBuffer' instead.")]] serializationDeferredDataBufferType
    : CSimpleRTTITypeSerializationDeferredDataBuffer
{
};
struct [[deprecated("Use 'CSimpleRTTITypeVariant' instead.")]] VariantType : CSimpleRTTITypeVariant
{
};
struct [[deprecated("Use 'CSimpleRTTITypeCDateTime' instead.")]] CDateTimeType : CSimpleRTTITypeCDateTime
{
};
struct [[deprecated("Use 'CSimpleRTTITypeCGUID' instead.")]] CGUIDType : CSimpleRTTITypeCGUID
{
};
struct [[deprecated("Use 'CSimpleRTTITypeCRUID' instead.")]] CRUIDType : CSimpleRTTITypeCRUID
{
};
struct [[deprecated("Use 'CSimpleRTTITypeCRUIDRef' instead.")]] CRUIDRefType : CSimpleRTTITypeCRUIDRef
{
};
struct [[deprecated("Use 'CSimpleRTTITypeEditorObjectID' instead.")]] EditorObjectIDType : CSimpleRTTITypeEditorObjectID
{
};
struct [[deprecated("Use 'CSimpleRTTITypeGamedataLocKeyWrapper' instead.")]] gamedataLocKeyWrapperType
    : CSimpleRTTITypeGamedataLocKeyWrapper
{
};
struct [[deprecated("Use 'CSimpleRTTITypeMessageResourcePath' instead.")]] MessageResourcePathType
    : CSimpleRTTITypeMessageResourcePath
{
};
struct [[deprecated("Use 'CSimpleRTTITypeNodeRef' instead.")]] NodeRefType : CSimpleRTTITypeNodeRef
{
};
struct [[deprecated("Use 'CSimpleRTTITypeRuntimeEntityRef' instead.")]] RuntimeEntityRefType
    : CSimpleRTTITypeRuntimeEntityRef
{
};

struct [[deprecated("Use 'CRTTIBaseArrayType' instead.")]] CArrayBase : CRTTIBaseArrayType
{
};
struct [[deprecated("Use 'CRTTIArrayType' instead.")]] CArray : CRTTIArrayType
{
};
struct [[deprecated("Use 'CRTTIStaticArrayType' instead.")]] CStaticArray : CRTTIStaticArrayType
{
};
struct [[deprecated("Use 'CRTTINativeArrayType' instead.")]] CNativeArray : CRTTINativeArrayType
{
};

struct [[deprecated("Use 'CRTTIHandleType' instead.")]] CHandle : CRTTIHandleType
{
};
struct [[deprecated("Use 'CRTTIWeakHandleType' instead.")]] CWeakHandle : CRTTIWeakHandleType
{
};
struct [[deprecated("Use 'CRTTIResourceReferenceType' instead.")]] CResourceReference : CRTTIResourceReferenceType
{
};

struct [[deprecated("Use 'CRTTIResourceAsyncReferenceType' instead.")]] CResourceAsyncReference
    : CRTTIResourceAsyncReferenceType
{
};

struct [[deprecated("Use 'CRTTILegacySingleChannelCurveType' instead.")]] CLegacySingleChannelCurve
    : CRTTILegacySingleChannelCurveType
{
};
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/RTTITypes-inl.hpp>
#endif
