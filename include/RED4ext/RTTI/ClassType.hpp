#pragma once

#include <RED4ext/RTTI/IType.hpp>

#include <RED4ext/Callback.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/HashMap.hpp>
#include <RED4ext/InstanceType.hpp>
#include <RED4ext/Map.hpp>
#include <RED4ext/Utils.hpp>

#include <type_traits>

namespace RED4ext
{
struct Variant;

namespace rtti
{
struct Property;
struct Function;
struct NativeMemberFunction;

struct ClassType : IType
{
    struct Flags
    {
        uint32_t isAbstract : 1;                      // 00
        uint32_t isNative : 1;                        // 01
        uint32_t isScriptedClass : 1;                 // 02
        uint32_t isScriptedStruct : 1;                // 03
        uint32_t hasNoDefaultObjectSerialization : 1; // 04
        uint32_t isAlwaysTransient : 1;               // 05
        uint32_t isImportOnly : 1;                    // 06
        uint32_t isPrivate : 1;                       // 07
        uint32_t isProtected : 1;                     // 08
        uint32_t isTestOnly : 1;                      // 09
        uint32_t isSavable : 1;                       // 0A
        uint32_t b10 : 21;                            // 0B
    };
    RED4EXT_ASSERT_SIZE(ClassType::Flags, 0x4);

    struct Connector
    {
        Callback<void (*)(IScriptable&, Handle<IScriptable>&), 16> callback; // 00
        CName callbackName;                                                  // 18
        int16_t eventTypeId;                                                 // 20
        bool isScripted;                                                     // 22
    };
    RED4EXT_ASSERT_SIZE(ClassType::Connector, 0x28);
    RED4EXT_ASSERT_OFFSET(ClassType::Connector, callbackName, 0x18);
    RED4EXT_ASSERT_OFFSET(ClassType::Connector, isScripted, 0x22);

    ClassType(CName aName, uint32_t aSize, Flags aFlags);

    virtual CName GetName() const final;                                                                   // 08
    virtual uint32_t GetSize() const final;                                                                // 10
    virtual uint32_t GetAlignment() const final;                                                           // 18
    virtual ERTTIType GetType() const final;                                                               // 20
    virtual CName GetRefName() const final;                                                                // 30
    virtual void Construct(ScriptData* aMemory) const final;                                               // 38
    virtual void Destruct(ScriptData* aMemory) const final;                                                // 40
    virtual bool Serialize(BaseStream* aStream, ScriptData* aData, ISerializable* aDataOwner) const final; // 60
    virtual bool ToString(const ScriptData* aObject, CString& aOutString) const final;                           // 68
    virtual bool SerializeToText(int64_t aWriter, const ScriptData* aData) final;                                     // 80
    virtual bool SerializeFromText(int64_t aReader, ScriptData* aData) final;                                   // 88
    virtual bool ReadValue(int64_t aContext, ScriptData* aData, const CString& aPath, int64_t aOutValue) final;              // 90
    virtual bool WriteValue(int64_t aContext, ScriptData* aData, const CString& aPath, const int64_t aValue, bool a5) final; // 98
    virtual bool IsPropertyReadOnly(int64_t aContext, const CString& aPath, bool& aOutIsReadyOnly) final;                    // A0
    virtual void RebuildParentHierarchy(ScriptData* aObject, ISerializable* aParent) const final;          // B0
    virtual void sub_C0();                                                                                 // C0
    virtual uint32_t GetMaxAlignment() const;                                                              // C8
    virtual bool sub_D0() const;                                                                           // D0
    virtual void OnConstruct(ScriptData* aMemory) const = 0;                                               // D8
    virtual void OnDestruct(ScriptData* aMemory) const = 0;                                                // E0
    virtual void* AllocMemory() const = 0;                                                                 // E8

    ScriptData* CreateObject(bool aZeroMemory = false) const;
    bool IsA(const IType* aType) const;
    bool DeepCompare(const ScriptData* aLhs, const ScriptData* aRhs, uint32_t a3);

    void InitializeScriptedProperties(ScriptData* aObject) const;
    void InitializeScriptDefaultValues(ScriptData* aObject) const;
    void InitializeProperties(ScriptData* aObject);

    void AddProperty(const Property* aProp);
    void AddPropertyOverride(const Property* aProp);
    const Property* FindProperty(const CName aName) const;
    const Property* FindPropertyOverride(const CName aName) const;
    void GetProperties(DynArray<Property*>& aOutProps);

    void RegisterFunction(NativeMemberFunction* aFunc);
    void AddFunction(const Function* aFunc);
    void AddStaticFunction(const Function* aStaticFunc);
    const Function* FindFunction(const CName aShortName) const;
    const Function* FindFunctionByHash(uint64_t aHash) const;

    void ClearScriptedData();

#pragma region deprecated
    [[deprecated("Use 'FindProperty()' instead.")]]
    inline void GetProperty(CName aName) const
    {
        FindProperty(aName);
    }

    [[deprecated("Use 'FindFunction()' instead.")]]
    inline void GetFunction(CName aName) const
    {
        FindFunction(aName);
    }

    [[deprecated("Use 'OnConstruct()' instead.")]]
    inline void ConstructCls(ScriptData* aMemory) const
    {
        OnConstruct(aMemory);
    }

    [[deprecated("Use 'OnDestruct()' instead.")]]
    inline void DestructCls(ScriptData* aMemory) const
    {
        OnDestruct(aMemory);
    }

    [[deprecated("Use 'CreateObject()' instead.")]]
    inline ScriptData* CreateInstance(bool aZeroMemory = false) const
    {
        return CreateObject(aZeroMemory);
    }
#pragma endregion

    ClassType* parent;                              // 10
    CName name;                                     // 18
    CName scriptRefName;                            // 20
    DynArray<const Property*> directProps;          // 28 - properties direct to this class
    DynArray<const Property*> overriddenProps;      // 38
    DynArray<const Function*> funcs;                // 48
    DynArray<const Function*> staticFuncs;          // 58
    uint32_t nativeSize;                            // 68 - size of the class nativley
    uint32_t scriptSize;                            // 6C - size of the class as calculated from script layout
    Flags flags;                                    // 70
    uint32_t alignment;                             // 74
    HashMap<CName, const Function*> funcsByName;    // 78
    HashMap<uint64_t, const Function*> funcsByHash; // A8
    int64_t unkD8;                                  // D8
    int64_t unkE0;                                  // E0
    HashMap<CName, const Property*> propsByName;    // E8
    DynArray<const Property*> allProps;             // 118 - all properties, including those of parent classes
    DynArray<const Property*> unk128;               // 128
    DynArray<const Property*> unk138;               // 138 - Only RT_Class types?
    DynArray<void*> unk148;                         // 148
    Map<CName, Variant*> defaultPropValues;         // 158
    HashMap<void*, void*> unk180;                   // 180
    DynArray<Connector> eventConnectors;            // 1B0
    uint32_t connectedEventsMask[64];               // 1C0 - Bitset of event types that this class listens to
    std::atomic<int16_t> eventTypeId;               // 2C0 - Assigned to event classes only
    int32_t unk2C4;                                 // 2C4
    SharedSpinLock unk2C8;                          // 2C8
    uint8_t unk2C9;                                 // 2C9
};
RED4EXT_ASSERT_SIZE(ClassType, 0x2D0);
RED4EXT_ASSERT_OFFSET(ClassType, parent, 0x10);
RED4EXT_ASSERT_OFFSET(ClassType, name, 0x18);
RED4EXT_ASSERT_OFFSET(ClassType, directProps, 0x28);
RED4EXT_ASSERT_OFFSET(ClassType, funcs, 0x48);
RED4EXT_ASSERT_OFFSET(ClassType, nativeSize, 0x68);
RED4EXT_ASSERT_OFFSET(ClassType, flags, 0x70);
RED4EXT_ASSERT_OFFSET(ClassType, alignment, 0x74);
RED4EXT_ASSERT_OFFSET(ClassType, allProps, 0x118);
RED4EXT_ASSERT_OFFSET(ClassType, defaultPropValues, 0x158);
RED4EXT_ASSERT_OFFSET(ClassType, eventConnectors, 0x1B0);

} // namespace rtti
struct [[deprecated("Use 'rtti::ClassType' instead.")]] CClass : rtti::ClassType
{
};
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/rtti/ClassType-inl.hpp>
#endif
