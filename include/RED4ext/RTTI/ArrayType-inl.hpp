#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/RTTI/ArrayType.hpp>
#endif

#pragma region IBaseArrayType
RED4EXT_INLINE bool RED4ext::rtti::IBaseArrayType::ToString(const ScriptData* aObject, CString& aOutString) const
{
    using func_t = bool (*)(const IBaseArrayType*, const void*, CString&);
    static UniversalRelocFunc<func_t> func(2132284612);
    return func(this, aObject, aOutString);
}

RED4EXT_INLINE bool RED4ext::rtti::IBaseArrayType::SerializeToText(int64_t aWriter, const ScriptData* aData) const
{
    using func_t = bool (*)(const IBaseArrayType*, int64_t, const void*);
    static UniversalRelocFunc<func_t> func(3473676824);
    return func(this, aWriter, aData);
}

RED4EXT_INLINE bool RED4ext::rtti::IBaseArrayType::SerializeFromText(int64_t aReader, ScriptData* aData) const
{
    using func_t = bool (*)(const IBaseArrayType*, int64_t, void*);
    static UniversalRelocFunc<func_t> func(129243838);
    return func(this, aReader, aData);
}

RED4EXT_INLINE bool RED4ext::rtti::IBaseArrayType::ReadValue(int64_t aContext, const ScriptData* aData, const CString& aPath, int64_t aOutValue) const
{
    using func_t = bool (*)(const IBaseArrayType*, int64_t, const void*, const CString&, int64_t);
    static UniversalRelocFunc<func_t> func(3196205339);
    return func(this, aContext, aData, aPath, aOutValue);
}

RED4EXT_INLINE bool RED4ext::rtti::IBaseArrayType::WriteValue(int64_t aContext, ScriptData* aData, const CString& aPath, const int64_t aValue, bool a5) const
{
    using func_t = bool (*)(const IBaseArrayType*, int64_t, const void*, const CString&, const int64_t, bool);
    static UniversalRelocFunc<func_t> func(4189594263);
    return func(this, aContext, aData, aPath, aValue, a5);
}

RED4EXT_INLINE bool RED4ext::rtti::IBaseArrayType::IsPropertyReadOnly(int64_t aContext, const CString& aPath,
                                                                      bool& aOutIsReadyOnly) const
{
    using func_t = bool (*)(const IBaseArrayType*, int64_t, const CString&, bool&);
    static UniversalRelocFunc<func_t> func(303288300);
    return func(this, aContext, aPath, aOutIsReadyOnly);
}

RED4EXT_INLINE void RED4ext::rtti::IBaseArrayType::RebuildParentHierarchy(ScriptData* aObject, ISerializable* aParent) const
{
    using func_t = void (*)(const IBaseArrayType*, void*, ISerializable*);
    static UniversalRelocFunc<func_t> func(652155713);
    func(this, aObject, aParent);
}

RED4EXT_INLINE RED4ext::rtti::IType* RED4ext::rtti::IBaseArrayType::ArrayGetInnerType() const
{
    return innerType;
}
#pragma endregion

#pragma region ArrayType
RED4EXT_INLINE const RED4ext::red::DynArrayAccessor* RED4ext::rtti::ArrayType::GetArrayAccessor(
    const ScriptData* aArray) const
{
    return std::bit_cast<red::DynArrayAccessor*>(aArray);
}

RED4EXT_INLINE RED4ext::red::DynArrayAccessor* RED4ext::rtti::ArrayType::GetArrayAccessor(ScriptData* aArray) const
{
    return std::bit_cast<red::DynArrayAccessor*>(aArray);
}

RED4EXT_INLINE RED4ext::ScriptData* RED4ext::rtti::ArrayType::GetArrayData(const ScriptData* aArray) const
{
    return aArray ? GetArrayAccessor(aArray)->Data() : nullptr;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ArrayType::GetArraySize(const ScriptData* aArray) const
{
    return aArray ? GetArrayAccessor(aArray)->Size() : 0;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ArrayType::GetArrayMaxSize(const ScriptData* aArray) const
{
    return aArray ? GetArrayAccessor(aArray)->Capacity() : 0;
}

RED4EXT_INLINE const RED4ext::ScriptData* RED4ext::rtti::ArrayType::GetArrayElement(const ScriptData* aArray,
                                                                                    uint32_t aIndex) const
{
    return aArray ? GetArrayAccessor(aArray)->GetElement(innerType->GetSize(), aIndex) : nullptr;
}

RED4EXT_INLINE RED4ext::ScriptData* RED4ext::rtti::ArrayType::GetArrayElement(ScriptData* aArray, uint32_t aIndex) const
{
    return aArray ? GetArrayAccessor(aArray)->GetElement(innerType->GetSize(), aIndex) : nullptr;
}

RED4EXT_INLINE int32_t RED4ext::rtti::ArrayType::AddArrayElement(ScriptData* aArray, uint32_t aAmount, const Memory::IAllocator& aAllocator) const
{
    auto* array = GetArrayAccessor(aArray);
    if (!array) 
    {
        return -1;
    }

    array->SetAllocator(&aAllocator);

    uint32_t lastIndex = array->Size();
    array->Resize(array->Size() + aAmount, innerType->GetSize(), innerType->GetAlignment());
    std::memset(GetArrayElement(array, lastIndex), 0, innerType->GetSize() * aAmount);

    for (uint32_t i = 0; i < aAmount; i++)
    {
        innerType->Construct(GetArrayElement(array, i + lastIndex));
    }

    return lastIndex;
}

RED4EXT_INLINE bool RED4ext::rtti::ArrayType::DeleteArrayElement(ScriptData* aArray, int32_t aIndex) const
{
    auto* array = GetArrayAccessor(aArray);
    if (!array || array->Size() <= aIndex || aIndex < 0)
    {
        return false;
    }

    for (uint32_t i = 0; i < array->Size(); i++)
    {
        innerType->Copy(GetArrayElement(array, i - 1), GetArrayElement(array, i));
    }

    innerType->Destruct(GetArrayElement(array, array->Size() - 1));
    array->Resize(array->Size() - 1, innerType->GetSize(), innerType->GetAlignment());

    return true;
}

RED4EXT_INLINE bool RED4ext::rtti::ArrayType::InsertArrayElementAt(ScriptData* aArray, int32_t aIndex) const
{
    auto* array = GetArrayAccessor(aArray);
    if (!array || array->Size() < aIndex || aIndex < 0)
    {
        return false;
    }

    array->Resize(array->Size() + 1, innerType->GetSize(), innerType->GetAlignment());

    ScriptData* newElement = GetArrayElement(array, array->Size() - 1);
    std::memset(newElement, 0, innerType->GetSize());
    innerType->Construct(newElement);

    for (uint32_t i = array->Size(); i > aIndex; i--)
    {
        innerType->Copy(GetArrayElement(array, i), GetArrayElement(array, i - 1));
    }

    innerType->Destruct(GetArrayElement(array, aIndex));

    return true;
}

RED4EXT_INLINE void RED4ext::rtti::ArrayType::DestroyArrayElements(ScriptData* aArray) const
{
    auto* array = GetArrayAccessor(aArray);
    if (array && innerType->sub_78())
    {
        for (uint32_t i = 0; i < array->Size(); i++)
        {
            innerType->Destruct(GetArrayElement(array, i));
        }
    }
    array->Clear();
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::ArrayType::GetName() const
{
    return name;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ArrayType::GetSize() const
{
    return sizeof(DynArray<void*>);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ArrayType::GetAlignment() const
{
    return __alignof(DynArray<void*>);
}

RED4EXT_INLINE void RED4ext::rtti::ArrayType::Construct(ScriptData* aMemory) const
{
    std::construct_at<red::DynArrayAccessor>(static_cast<red::DynArrayAccessor*>(aMemory));
}

RED4EXT_INLINE void RED4ext::rtti::ArrayType::Destruct(ScriptData* aMemory) const
{
    DestroyArrayElements(aMemory);
    GetArrayAccessor(aMemory)->ShrinkToSize(innerType->GetSize(), innerType->GetAlignment());
}

RED4EXT_INLINE bool RED4ext::rtti::ArrayType::Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3) const
{
    uint32_t lhsArraySize = GetArraySize(aLhs);
    uint32_t rhsArraySize = GetArraySize(aRhs);
    if (lhsArraySize != rhsArraySize)
    {
        return false;
    }

    for (uint32_t i = 0; i < lhsArraySize; i++)
    {
        if (!innerType->Compare(GetArrayElement(aLhs, i), GetArrayElement(aRhs, i), a3)) 
        {
            return false;
        }
    }

    return true;
}

// 4244180139
RED4EXT_INLINE void RED4ext::rtti::ArrayType::Copy(ScriptData* aDest, const ScriptData* aSrc) const
{
    auto* destArray = GetArrayAccessor(aDest);
    auto* srcArray = GetArrayAccessor(aSrc);

    DestroyArrayElements(destArray);

    if (uint32_t srcSize = GetArraySize(srcArray))
    {
        destArray->ResizeExact(destArray->Size() + srcSize, innerType->GetSize(), innerType->GetAlignment());
        std::memset(destArray->Data(), 0, innerType->GetSize() * srcSize);

        for (uint32_t i = 0; i < srcSize; i++)
        {
            const ScriptData* srcElement = GetArrayElement(srcArray, i);
            ScriptData* destElement = GetArrayElement(destArray, i);
            innerType->Construct(destElement);
            innerType->Copy(destElement, srcElement);
        }
    }
}

// 3611691944
RED4EXT_INLINE void RED4ext::rtti::ArrayType::Move(ScriptData* aLhs, ScriptData* aRhs) const
{
    DestroyArrayElements(aLhs);
    GetArrayAccessor(aLhs)->Swap(*GetArrayAccessor(aRhs));
}

RED4EXT_INLINE bool RED4ext::rtti::ArrayType::Serialize(BaseStream* aStream, ScriptData* aInstanceData, ISerializable* aDataOwner) const
{
    using func_t = bool (*)(const ArrayType*, BaseStream*, void*, ISerializable*);
    static UniversalRelocFunc<func_t> func(1557534736);
    return func(this, aStream, aInstanceData, aDataOwner);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ArrayType::ArrayGetArraySize(const ScriptData* aArray) const
{
    return GetArraySize(aArray);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ArrayType::ArrayGetArrayMaxSize(const ScriptData* aArray) const
{
    return (std::numeric_limits<uint32_t>::max)();
}

RED4EXT_INLINE const RED4ext::ScriptData* RED4ext::rtti::ArrayType::ArrayGetArrayElement(const ScriptData* aArray, uint32_t aIndex) const
{
    return GetArrayElement(aArray, aIndex);
}

RED4EXT_INLINE RED4ext::ScriptData* RED4ext::rtti::ArrayType::ArrayGetArrayElement(ScriptData* aArray, uint32_t aIndex) const
{
    return GetArrayElement(aArray, aIndex);
}

RED4EXT_INLINE int32_t RED4ext::rtti::ArrayType::ArrayAddElement(ScriptData* aArray, int32_t aAmount) const
{
    return AddArrayElement(aArray, aAmount, *Memory::DefaultAllocator::Get());
}

RED4EXT_INLINE bool RED4ext::rtti::ArrayType::ArrayDeleteElement(ScriptData* aArray, int32_t aIndex) const
{
    return DeleteArrayElement(aArray, aIndex);
}

RED4EXT_INLINE bool RED4ext::rtti::ArrayType::ArrayInsertElement(ScriptData* aArray, int32_t aIndex) const
{
    return InsertArrayElementAt(aArray, aIndex);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ArrayType::ArrayResize(ScriptData* aArray, uint32_t aSize) const
{
    GetArrayAccessor(aArray)->ResizeExact(aSize, innerType->GetSize(), innerType->GetAlignment());
    return aSize;
}
#pragma endregion

#pragma region StaticArrayType
RED4EXT_INLINE RED4ext::red::StaticArrayAccessor* RED4ext::rtti::StaticArrayType::GetArrayAccessor(const ScriptData* aArray) const
{
    return std::bit_cast<red::StaticArrayAccessor*>(aArray);
}

RED4EXT_INLINE RED4ext::ScriptData* RED4ext::rtti::StaticArrayType::GetArrayData(const ScriptData* aArray) const
{
    return GetArrayAccessor(aArray)->Data();
}

RED4EXT_INLINE uint32_t RED4ext::rtti::StaticArrayType::GetArraySize(const ScriptData* aArray) const
{
    return GetArrayAccessor(aArray)->Size(innerType->GetSize(), maxSize);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::StaticArrayType::GetArrayMaxSize(const ScriptData* aArray) const
{
    return maxSize;
}

RED4EXT_INLINE const RED4ext::ScriptData* RED4ext::rtti::StaticArrayType::GetArrayElement(const ScriptData* aArray, uint32_t aIndex) const
{
    return std::bit_cast<uint8_t*>(aArray) + innerType->GetSize() * aIndex;
}

RED4EXT_INLINE RED4ext::ScriptData* RED4ext::rtti::StaticArrayType::GetArrayElement(ScriptData* aArray, uint32_t aIndex) const
{
    return std::bit_cast<uint8_t*>(aArray) + innerType->GetSize() * aIndex;
}

RED4EXT_INLINE int32_t RED4ext::rtti::StaticArrayType::AddArrayElement(ScriptData* aArray, uint32_t aAmount) const
{
    auto* array = GetArrayAccessor(aArray);
    if (!array) 
    {
        return -1;
    }

    const uint32_t innerTypeSize = innerType->GetSize();
    const uint32_t arrSize = array->Size(innerTypeSize, maxSize);

    const uint32_t lastIndex = arrSize;
    if (lastIndex + aAmount <= maxSize)
    {
        array->Resize(innerTypeSize, maxSize, arrSize + aAmount);
        std::memset(GetArrayElement(array, lastIndex), 0, innerTypeSize * aAmount);
        for (uint32_t i = 0; i < aAmount; i++)
        {
            innerType->Construct(GetArrayElement(array, i + lastIndex));
        }
    }

    return lastIndex;
}

RED4EXT_INLINE bool RED4ext::rtti::StaticArrayType::DeleteArrayElement(ScriptData* aArray, int32_t aIndex) const
{
    auto* array = GetArrayAccessor(aArray);
    if (!array) 
    {
        return false;
    }

    const uint32_t innerTypeSize = innerType->GetSize();
    const uint32_t arrSize = array->Size(innerTypeSize, maxSize);

    if (aIndex >= 0 && aIndex < arrSize)
    {
        for (uint32_t i = aIndex + 1; i < arrSize; i++)
        {
            innerType->Copy(GetArrayElement(array, i - 1), GetArrayElement(array, i));
        }
        innerType->Destruct(GetArrayElement(array, arrSize - 1));
        array->Resize(innerTypeSize, maxSize, arrSize - 1);
    }

    return true;
}

RED4EXT_INLINE bool RED4ext::rtti::StaticArrayType::InsertArrayElementAt(ScriptData* aArray, int32_t aIndex) const
{
    auto* array = GetArrayAccessor(aArray);
    if (!array) 
    {
        return false;
    }

    const uint32_t innerTypeSize = innerType->GetSize();
    const uint32_t arrSize = array->Size(innerType->GetSize(), maxSize);

    if (aIndex >= 0 && aIndex < arrSize && arrSize < maxSize)
    {
        array->Resize(innerTypeSize, maxSize, arrSize + 1);

        void* newElement = GetArrayElement(array, arrSize - 1);
        std::memset(newElement, 0, innerTypeSize);
        innerType->Construct(newElement);

        for (uint32_t i = arrSize - 1; i > aIndex; i--)
        {
            innerType->Copy(GetArrayElement(array, i - 1), GetArrayElement(array, i));
        }
        innerType->Destruct(GetArrayElement(array, aIndex));
    }

    return true;
}

RED4EXT_INLINE void RED4ext::rtti::StaticArrayType::DestroyArrayElements(ScriptData* aArray) const
{
    if (innerType->sub_78())
    {
        for (uint32_t i = 0; i < ArrayGetArraySize(aArray); i++)
        {
            innerType->Destruct(GetArrayElement(aArray, i));
        }
    }

    GetArrayAccessor(aArray)->Clear(innerType->GetSize(), maxSize);
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::StaticArrayType::GetName() const
{
    return name;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::StaticArrayType::GetSize() const
{
    uint32_t arrAlignment = (std::max)(static_cast<uint32_t>(alignof(uint32_t)), innerType->GetAlignment());
    uint32_t arrSize = innerType->GetSize() * maxSize + sizeof(uint32_t);
    return AlignUp(arrSize, arrAlignment);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::StaticArrayType::GetAlignment() const
{
    return (std::max)(static_cast<uint32_t>(alignof(uint32_t)), innerType->GetAlignment());
}

RED4EXT_INLINE RED4ext::ERTTIType RED4ext::rtti::StaticArrayType::GetType() const
{
    return ERTTIType::StaticArray;
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::StaticArrayType::GetRefName() const
{
    return scriptRefName;
}

RED4EXT_INLINE void RED4ext::rtti::StaticArrayType::Construct(ScriptData* aMemory) const
{
    GetArrayAccessor(aMemory)->Clear(innerType->GetSize(), maxSize);
}

RED4EXT_INLINE void RED4ext::rtti::StaticArrayType::Destruct(ScriptData* aMemory) const
{
    DestroyArrayElements(aMemory);
}

RED4EXT_INLINE bool RED4ext::rtti::StaticArrayType::Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3) const
{
    uint32_t lhsArraySize = ArrayGetArraySize(aLhs);
    uint32_t rhsArraySize = ArrayGetArraySize(aRhs);
    if (lhsArraySize != rhsArraySize)
    {
        return false;
    }

    for (uint32_t i = 0; i < lhsArraySize; i++)
    {
        if (!innerType->Compare(GetArrayElement(aLhs, i), GetArrayElement(aRhs, i), a3)) 
        {
            return false;
        }
    }

    return true;
}

RED4EXT_INLINE void RED4ext::rtti::StaticArrayType::Copy(ScriptData* aDest, const ScriptData* aSrc) const
{
    auto* destArray = GetArrayAccessor(aDest);
    auto* srcArray = GetArrayAccessor(aSrc);

    Destruct(destArray);

    uint32_t innerTypeSize = innerType->GetSize();

    if (uint32_t srcSize = ArrayGetArraySize(srcArray))
    {
        destArray->Resize(innerTypeSize, maxSize, destArray->Size(innerTypeSize, maxSize) + srcSize);

        for (uint32_t i = 0; i < srcSize; i++)
        {
            ScriptData* srcElement = GetArrayElement(srcArray, i);
            ScriptData* destElement = GetArrayElement(destArray, i);
            std::memset(destElement, 0, innerTypeSize);
            innerType->Construct(destElement);
            innerType->Copy(destElement, srcElement);
        }
    }
}

RED4EXT_INLINE bool RED4ext::rtti::StaticArrayType::Serialize(BaseStream* aStream, ScriptData* aData, ISerializable* aDataOwner) const
{
    using func_t = bool (*)(const StaticArrayType*, BaseStream*, void*, ISerializable*);
    static UniversalRelocFunc<func_t> func(162536056);
    return func(this, aStream, aData, aDataOwner);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::StaticArrayType::ArrayGetArraySize(const ScriptData* aArray) const
{
    return GetArraySize(aArray);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::StaticArrayType::ArrayGetArrayMaxSize(const ScriptData* aArray) const
{
    return GetArrayMaxSize(aArray);
}

RED4EXT_INLINE const RED4ext::ScriptData* RED4ext::rtti::StaticArrayType::ArrayGetArrayElement(const ScriptData* aArray, uint32_t aIndex) const
{
    return GetArrayElement(aArray, aIndex);
}

RED4EXT_INLINE RED4ext::ScriptData* RED4ext::rtti::StaticArrayType::ArrayGetArrayElement(ScriptData* aArray, uint32_t aIndex) const
{
    return GetArrayElement(aArray, aIndex);
}

RED4EXT_INLINE int32_t RED4ext::rtti::StaticArrayType::ArrayAddElement(ScriptData* aArray, int32_t aAmount) const
{
    return AddArrayElement(aArray, aAmount);
}

RED4EXT_INLINE bool RED4ext::rtti::StaticArrayType::ArrayDeleteElement(ScriptData* aArray, int32_t aIndex) const
{
    return DeleteArrayElement(aArray, aIndex);
}

RED4EXT_INLINE bool RED4ext::rtti::StaticArrayType::ArrayInsertElement(ScriptData* aArray, int32_t aIndex) const
{
    return InsertArrayElementAt(aArray, aIndex);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::StaticArrayType::ArrayResize(ScriptData* aArray, uint32_t aSize) const
{
    const uint32_t clampedSize = (std::min)(aSize, maxSize);
    GetArrayAccessor(aArray)->Resize(innerType->GetSize(), maxSize, clampedSize);
    return clampedSize;
}
#pragma endregion

#pragma region NativeArrayType

RED4EXT_INLINE RED4ext::red::NativeArrayAccessor* RED4ext::rtti::NativeArrayType::GetArrayAccessor(const ScriptData* aArray) const
{
    return std::bit_cast<red::NativeArrayAccessor*>(aArray);
}

RED4EXT_INLINE const RED4ext::ScriptData* RED4ext::rtti::NativeArrayType::GetArrayElement(const ScriptData* aArray, uint32_t aIndex) const
{
    return GetArrayAccessor(aArray)->GetElement(innerType->GetSize(), size, aIndex);
}

RED4EXT_INLINE RED4ext::ScriptData* RED4ext::rtti::NativeArrayType::GetArrayElement(ScriptData* aArray, uint32_t aIndex) const
{
    return GetArrayAccessor(aArray)->GetElement(innerType->GetSize(), size, aIndex);
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::NativeArrayType::GetName() const
{
    return name;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::NativeArrayType::GetSize() const
{
    return innerType->GetSize() * size;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::NativeArrayType::GetAlignment() const
{
    return innerType->GetAlignment();
}

RED4EXT_INLINE RED4ext::ERTTIType RED4ext::rtti::NativeArrayType::GetType() const
{
    return ERTTIType::NativeArray;
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::NativeArrayType::GetRefName() const
{
    return scriptRefName;
}

RED4EXT_INLINE void RED4ext::rtti::NativeArrayType::Construct(ScriptData* aMemory) const
{
    for (uint32_t i = 0; i < size; i++)
    {
        innerType->Construct(GetArrayElement(aMemory, i));
    }
}

RED4EXT_INLINE void RED4ext::rtti::NativeArrayType::Destruct(ScriptData* aMemory) const
{
    if (innerType->sub_78())
    {
        for (uint32_t i = 0; i < size; i++)
    {
        innerType->Destruct(GetArrayElement(aMemory, i));
    }
    }
}

RED4EXT_INLINE bool RED4ext::rtti::NativeArrayType::Compare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3) const
{
    for (uint32_t i = 0; i < size; i++)
    {
        if (!innerType->Compare(GetArrayElement(aLhs, i), GetArrayElement(aRhs, i), a3)) 
        {
            return false;
        }
    }
    return true;
}

RED4EXT_INLINE void RED4ext::rtti::NativeArrayType::Copy(ScriptData* aDest, const ScriptData* aSrc) const
{
    Destruct(aDest);

    for (uint32_t i = 0; i < size; i++)
    {
        innerType->Copy(GetArrayElement(aDest, i), GetArrayElement(aSrc, i));
    }
}

RED4EXT_INLINE bool RED4ext::rtti::NativeArrayType::Serialize(BaseStream* aStream, ScriptData* aInstanceData, ISerializable* aDataOwner) const
{
    using func_t = bool (*)(const NativeArrayType*, BaseStream*, void*, ISerializable*);
    static UniversalRelocFunc<func_t> func(155196023);
    return func(this, aStream, aInstanceData, aDataOwner);
}

RED4EXT_INLINE bool RED4ext::rtti::NativeArrayType::ArrayIsResizable() const
{
    return false;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::NativeArrayType::ArrayGetArraySize(const ScriptData* aArray) const
{
    return size;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::NativeArrayType::ArrayGetArrayMaxSize(const ScriptData* aArray) const
{
    return size;
}

RED4EXT_INLINE const RED4ext::ScriptData* RED4ext::rtti::NativeArrayType::ArrayGetArrayElement(const ScriptData* aArray, uint32_t aIndex) const
{
    return GetArrayElement(aArray, aIndex);
}

RED4EXT_INLINE RED4ext::ScriptData* RED4ext::rtti::NativeArrayType::ArrayGetArrayElement(ScriptData* aArray, uint32_t aIndex) const
{
    return GetArrayElement(aArray, aIndex);
}

RED4EXT_INLINE int32_t RED4ext::rtti::NativeArrayType::ArrayAddElement(ScriptData* aArray, int32_t aIndex) const
{
    return (std::numeric_limits<uint32_t>::max)();
}

RED4EXT_INLINE bool RED4ext::rtti::NativeArrayType::ArrayDeleteElement(ScriptData* aArray, int32_t aIndex) const
{
    return false;
}

RED4EXT_INLINE bool RED4ext::rtti::NativeArrayType::ArrayInsertElement(ScriptData* aArray, int32_t aIndex) const
{
    return false;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::NativeArrayType::ArrayResize(ScriptData* aArray, uint32_t aSize) const
{
    return (std::min)(aSize, size);
}
#pragma endregion
