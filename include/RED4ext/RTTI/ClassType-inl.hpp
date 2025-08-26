#pragma once

#ifdef RED4EXT_STATIC_LIB
#include <RED4ext/RTTI/ClassType.hpp>
#endif

#include <RED4ext/Relocation.hpp>

#include <RED4ext/RTTI/Function.hpp>
#include <RED4ext/RTTI/Property.hpp>

RED4EXT_INLINE RED4ext::rtti::ClassType::ClassType(CName aName, uint32_t aSize, Flags aFlags)
    : parent(nullptr)
    , name(aName)
    , scriptRefName(IType::GetRefName())
    , nativeSize(aSize)
    , flags(aFlags)
    , scriptSize(0)
    , alignment(4)
    , directProps(Memory::RTTIAllocator::Get())
    , overriddenProps(Memory::RTTIAllocator::Get())
    , funcs(Memory::RTTIAllocator::Get())
    , staticFuncs(Memory::RTTIAllocator::Get())
    , funcsByName(Memory::RTTIAllocator::Get())
    , funcsByHash(Memory::RTTIAllocator::Get())
    , unkD8(0)
    , unkE0(0)
    , propsByName(Memory::RTTIAllocator::Get())
    , allProps(Memory::RTTIAllocator::Get())
    , unk128(Memory::RTTIAllocator::Get())
    , unk138(Memory::RTTIAllocator::Get())
    , unk148(Memory::RTTIAllocator::Get())
    , defaultPropValues(Memory::ScriptAllocator::Get())
    , unk180(Memory::RTTIAllocator::Get())
    , eventConnectors(Memory::RTTIAllocator::Get())
    , eventTypeId(-1)
    , unk2C4(-1)
    , unk2C9(0xE6)
{
    std::memset(connectedEventsMask, 0, sizeof(connectedEventsMask));
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::ClassType::GetName() const
{
    return name;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ClassType::GetSize() const
{
    return nativeSize;
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ClassType::GetAlignment() const
{
    return alignment;
}

RED4EXT_INLINE RED4ext::ERTTIType RED4ext::rtti::ClassType::GetType() const
{
    return ERTTIType::Class;
}

RED4EXT_INLINE RED4ext::CName RED4ext::rtti::ClassType::GetRefName() const
{
    return scriptRefName;
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::Construct(ScriptInstance aMemory) const
{
    OnConstruct(aMemory);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::Destruct(ScriptInstance aMemory) const
{
    OnDestruct(aMemory);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::Serialize(BaseStream* aStream, ScriptInstance aInstance, ISerializable* aDataOwner) const
{
    using func_t = bool (*)(const ClassType*, BaseStream*, ScriptInstance, ISerializable*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_Unserialize);
    return func(this, aStream, aInstance, aDataOwner);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::ToString(const ScriptInstance aInstance, CString& aOut) const
{
    using func_t = bool (*)(const ClassType*, ScriptInstance, CString&);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_ToString);
    return func(this, aInstance, aOut);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::SerializeToText(int64_t a1, ScriptInstance aInstance)
{
    using func_t = bool (*)(const ClassType*, int64_t, ScriptInstance);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_80);
    return func(this, a1, aInstance);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::SerializeFromText(int64_t a1, ScriptInstance aInstance)
{
    using func_t = bool (*)(const ClassType*, int64_t, ScriptInstance);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_88);
    return func(this, a1, aInstance);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::ReadValue(int64_t a1, ScriptInstance aInstance, CString& a3, int64_t a4)
{
    using func_t = bool (*)(const ClassType*, int64_t, ScriptInstance, CString&, int64_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_90);
    return func(this, a1, aInstance, a3, a4);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::WriteValue(int64_t a1, ScriptInstance aInstance, CString& a3, int64_t a4,
                                                         bool a5)
{
    RED4EXT_UNUSED_PARAMETER(a5);

    using func_t = bool (*)(const ClassType*, int64_t, ScriptInstance, CString&, int64_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_90);
    return func(this, a1, aInstance, a3, a4);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::IsPropertyReadOnly(int64_t a1, CString& a2, bool a3)
{
    using func_t = bool (*)(const ClassType*, int64_t, CString&, bool);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_A0);
    return func(this, a1, a2, a3);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::RebuildParentHierarchy(int64_t a1, int64_t a2)
{
    using func_t = bool (*)(const ClassType*, int64_t, int64_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_B0);
    func(this, a1, a2);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::sub_C0()
{
    using func_t = void (*)(ClassType*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_C0);
    func(this);
}

RED4EXT_INLINE uint32_t RED4ext::rtti::ClassType::GetMaxAlignment() const
{
    using func_t = uint32_t (*)(const ClassType*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_GetMaxAlignment);
    return func(this);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::sub_D0() const
{
    using func_t = bool (*)(const ClassType*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_sub_D0);
    return func(this);
}

RED4EXT_INLINE RED4ext::ScriptInstance RED4ext::rtti::ClassType::CreateObject(bool aZeroMemory) const
{
    using func_t = ScriptInstance (*)(const ClassType*, uint32_t, bool);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_CreateInstance);
    return func(this, GetSize(), aZeroMemory);
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::IsA(const IType* aType) const
{
    if (this == aType)
    {
        return true;
    }

    if (parent)
    {
        return parent->IsA(aType);
    }

    return false;
}

RED4EXT_INLINE bool RED4ext::rtti::ClassType::DeepCompare(const ScriptInstance aLhs, const ScriptInstance aRhs,
                                                          uint32_t a3)
{
    using func_t = bool (*)(ClassType*, const void*, const void*, uint32_t);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::TTypedClass_IsEqual);
    return func(this, aLhs, aRhs, a3);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::InitializeScriptedProperties(ScriptInstance aMemory) const
{
    static UniversalRelocFunc<void (*)(const ClassType*, ScriptInstance)> func(
        Detail::AddressHashes::CClass_InitializeProperties);
    func(this, aMemory);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::InitializeScriptDefaultValues(ScriptInstance aMemory) const
{
    static UniversalRelocFunc<void (*)(const ClassType*, ScriptInstance)> func(
        Detail::AddressHashes::CClass_AssignDefaultValuesToProperties);
    func(this, aMemory);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::InitializeProperties(ScriptInstance aInstance)
{
    InitializeScriptedProperties(aInstance);
    InitializeScriptDefaultValues(aInstance);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::AddProperty(const Property* aProp)
{
    directProps.PushBack(aProp);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::AddPropertyOverride(const Property* aProp)
{
    overriddenProps.PushBack(aProp);
}

RED4EXT_INLINE const RED4ext::rtti::Property* RED4ext::rtti::ClassType::FindProperty(const CName aName) const
{
    // Not recreating this because they do something strage with overriden properties and I am not sure what exactly
    // they do.

    using func_t = Property* (*)(const ClassType*, CName);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_GetProperty);
    return func(this, aName);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::GetProperties(DynArray<Property*>& aProps)
{
    using func_t = Property* (*)(ClassType*, DynArray<Property*>&);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_GetProperties);
    func(this, aProps);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::AddFunction(const Function* aFunc)
{
    funcs.PushBack(aFunc);
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::AddStaticFunction(const Function* aStaticFunc)
{
    staticFuncs.PushBack(aStaticFunc);
}

RED4EXT_INLINE const RED4ext::rtti::Function* RED4ext::rtti::ClassType::FindFunction(CName aShortName) const
{
    if (auto** func = funcsByName.Get(aShortName))
    {
        return *func;
    }

    if (parent)
    {
        return parent->FindFunction(aShortName);
    }

    return nullptr;
}

RED4EXT_INLINE const RED4ext::rtti::Function* RED4ext::rtti::ClassType::FindFunctionByHash(uint64_t aHash) const
{
    if (auto** func = funcsByHash.Get(aHash))
    {
        return *func;
    }

    if (parent)
    {
        return parent->FindFunctionByHash(aHash);
    }

    return nullptr;
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::RegisterFunction(NativeMemberFunction* aFunc)
{
    if (aFunc->flags.isStatic)
    {
        staticFuncs.PushBack(aFunc);
    }
    else
    {
        funcs.PushBack(aFunc);
    }
}

RED4EXT_INLINE void RED4ext::rtti::ClassType::ClearScriptedData()
{
    using func_t = void (*)(ClassType*);
    static UniversalRelocFunc<func_t> func(Detail::AddressHashes::CClass_ClearScriptedData);
    func(this);
}
