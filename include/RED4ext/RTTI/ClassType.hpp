#pragma once

#include <RED4ext/RTTI/IType.hpp>

namespace RED4ext
{
namespace rtti
{
struct ClassType : rtti::IType
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

    struct Listener
    {
        Callback<void (*)(IScriptable&, Handle<IScriptable>&), 16> callback; // 00
        CName callbackName;                                                  // 18
        int16_t eventTypeId;                                                 // 20
        bool isScripted;                                                     // 22
    };
    RED4EXT_ASSERT_SIZE(ClassType::Listener, 0x28);
    RED4EXT_ASSERT_OFFSET(ClassType::Listener, callbackName, 0x18);
    RED4EXT_ASSERT_OFFSET(ClassType::Listener, isScripted, 0x22);

    ClassType(CName aName, uint32_t aSize, Flags aFlags);

    CName GetName() const final;                                                      // 08
    uint32_t GetSize() const final;                                                   // 10
    uint32_t GetAlignment() const final;                                              // 18
    rtti::ERTTIType GetType() const final;                                            // 20
    CName GetComputedName() const final;                                              // 30
    void Construct(void* aMemory) const final;                                        // 38
    void Destruct(void* aMemory) const final;                                         // 40
    bool Unserialize(BaseStream* aStream, void* aInstance, int64_t a3) const final;   // 60
    bool ToString(const void* aInstance, CString& aOut) const final;                  // 68
    bool sub_80(int64_t a1, void* aInstance) final;                                   // 80
    bool sub_88(int64_t a1, void* aInstance) final;                                   // 88
    bool sub_90(int64_t a1, void* aInstance, CString& a3, int64_t a4) final;          // 90
    bool sub_98(int64_t a1, void* aInstance, CString& a3, int64_t a4, bool a5) final; // 98
    bool sub_A0(int64_t a1, CString& a2, bool a3) final;                              // A0
    void sub_B0(int64_t a1, int64_t a2) final;                                        // B0

    virtual void sub_C0();                              // C0
    virtual uint32_t GetMaxAlignment() const;           // C8
    virtual bool sub_D0() const;                        // D0
    virtual void ConstructCls(void* aMemory) const = 0; // D8
    virtual void DestructCls(void* aMemory) const = 0;  // E0
    virtual void* AllocMemory() const = 0;              // E8

    void* CreateInstance(bool aZeroMemory = false) const;

    bool IsA(const rtti::IType* aType) const;

    CProperty* GetProperty(CName aName);
    CClassFunction* GetFunction(CName aShortName) const;

    void InitializeProperties(void* aInstance);
    void GetProperties(DynArray<CProperty*>& aProps);

    void RegisterFunction(CClassFunction* aFunc);

    void ClearScriptedData();

    [[deprecated("Use 'ConstructCls()' instead.")]]
    inline void InitCls(void* aMemory) const
    {
        ConstructCls(aMemory);
    }

    [[deprecated("Use 'DestructCls()' instead.")]]
    inline void DestroyCls(void* aMemory) const
    {
        DestructCls(aMemory);
    }

    [[deprecated("Use 'CreateInstance()' instead.")]]
    inline void* AllocInstance(bool aZeroMemory = false) const
    {
        return CreateInstance(aZeroMemory);
    }

    ClassType* parent;                           // 10
    CName name;                                  // 18
    CName computedName;                          // 20
    DynArray<CProperty*> props;                  // 28
    DynArray<CProperty*> overriddenProps;        // 38
    DynArray<CClassFunction*> funcs;             // 48
    DynArray<CClassStaticFunction*> staticFuncs; // 58
    uint32_t size;                               // 68
    uint32_t holderSize;                         // 6C
    Flags flags;                                 // 70
    uint32_t alignment;                          // 74
    HashMap<CName, CClassFunction*> funcsByName; // 78
    HashMap<void*, void*> unkA8;                 // A8
    int64_t unkD8;                               // D8
    int64_t unkE0;                               // E0
    HashMap<CName, CProperty*> propsByName;      // E8
    DynArray<CProperty*> unk118;                 // 118 - More entries than 0x28, will contain native props
    DynArray<void*> unk128;                      // 128
    DynArray<CProperty*> unk138;                 // 138 - Only RT_Class types?
    DynArray<void*> unk148;                      // 148
    Map<CName, Variant*> defaults;               // 158
    HashMap<void*, void*> unk180;                // 180
    DynArray<Listener> listeners;                // 1B0 - Event listeners
    int8_t listening[256];                       // 1C0 - Bitmask of event types that this class listens to
    int16_t eventTypeId;                         // 2C0 - Assigned to event classes only
    int32_t unk2C4;                              // 2C4
    SharedSpinLock unk2C8;                       // 2C8
    uint8_t unk2C9;                              // 2C9
};
RED4EXT_ASSERT_SIZE(ClassType, 0x2D0);
RED4EXT_ASSERT_OFFSET(ClassType, parent, 0x10);
RED4EXT_ASSERT_OFFSET(ClassType, name, 0x18);
RED4EXT_ASSERT_OFFSET(ClassType, props, 0x28);
RED4EXT_ASSERT_OFFSET(ClassType, overriddenProps, 0x38);
RED4EXT_ASSERT_OFFSET(ClassType, funcs, 0x48);
RED4EXT_ASSERT_OFFSET(ClassType, size, 0x68);
RED4EXT_ASSERT_OFFSET(ClassType, flags, 0x70);
RED4EXT_ASSERT_OFFSET(ClassType, alignment, 0x74);
} // namespace rtti
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/RTTI/ClassType-inl.hpp>
#endif