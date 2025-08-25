#pragma once

#include <Windows.h>
#include <cstdint>

#include <RED4ext/CName.hpp>
#include <RED4ext/Callback.hpp>
#include <RED4ext/Common.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/HashMap.hpp>
#include <RED4ext/Mutex.hpp>
#include <RED4ext/RTTITypes.hpp>
#include <RED4ext/SharedSpinLock.hpp>

namespace RED4ext
{
namespace rtti
{
struct Function;

struct ITypeSystem
{
    virtual IType* FindType(CName aName) = 0;                                                                        // 00
    virtual IType* FindTypeByHash(uint64_t aHash) = 0;                                                               // 08
    virtual ClassType* FindClass(CName aName) = 0;                                                                   // 10
    virtual EnumType* FindEnum(CName aName) = 0;                                                                     // 18
    virtual BitFieldType* FindBitField(CName aName) = 0;                                                             // 20
    virtual const Function* FindGlobalFunction(uint64_t aHash) = 0;                                                  // 28
    virtual const Function* FindGlobalFunction(CName aName) = 0;                                                     // 30
    virtual void sub_38() = 0;                                                                                       // 38
    virtual void EnumNativeTypes(DynArray<const IType*>& aTypes) = 0;                                                // 40
    virtual void EnumGlobalFunctions(DynArray<const Function*>& aFunctions) = 0;                                     // 48
    virtual void sub_50() = 0;                                                                                       // 50
    virtual void EnumFunctions(DynArray<const Function*>& aFunctions) = 0;                                           // 58
    virtual void EnumEnums(DynArray<const EnumType*>& aEnums, bool aScriptedOnly = false) = 0;                       // 60
    virtual void EnumBitFields(DynArray<const BitFieldType*>& aBitfields, bool aScriptedOnly = false) = 0;           // 68
    virtual void EnumClasses(ClassType* aParent, DynArray<const ClassType*>& aClasses, 
                                bool (*aFilter)(ClassType*) = nullptr, bool aIncludeAbstract = false) = 0;           // 70
    virtual void EnumDerivedClasses(ClassType* aParent, DynArray<const ClassType*>& aClasses) = 0;                   // 78
    virtual void RegisterType(IType* aType, uint64_t aHash) = 0;                                                     // 80
    virtual void RegisterTypeProxy(uint64_t aHash, uint64_t aProxyHash) = 0;                                         // 88
    virtual void RegisterTypeProxy(CName aName, CName aProxyName) = 0;                                               // 90 - added in 2.0
    virtual void UnregisterType(const IType* aType) = 0;                                                             // 98
    virtual void RegisterGlobalFunction(Function* aFunc) = 0;                                                        // A0
    virtual void UnregisterGlobalFunction(const Function* aFunc) = 0;                                                // A8
    virtual void ClearScriptedGlobalFunctions() = 0;                                                                 // B0
    virtual void ClearScriptedTypes() = 0;                                                                           // B8 - added in 2.0
    virtual void AddRegisterCallback(Callback<void (*)()>) = 0;                                                      // C0
    virtual void AddPostRegisterCallback(Callback<void (*)()>) = 0;                                                  // C8
    virtual void RegisterPendingTypes() = 0;                                                                         // D0
    virtual void sub_D8() = 0;                                                                                       // D8
    virtual void CreateScriptedClass(CName aName, ClassType::Flags aFlags, ClassType* aParent) = 0;                  // E0
    virtual void CreateScriptedEnum(CName aName, uint32_t aSize, DynArray<std::pair<CName, int64_t>>& aMembers) = 0; // E8
    virtual void CreateScriptedBitfield(CName aName, DynArray<std::pair<CName, uint64_t>>& aBits) = 0;               // F0
    virtual void RebuildRuntimeData() = 0;                                                                           // F8 - Called by script loader at the very end
    virtual void RegisterScriptAlias(CName aNativeName, CName aAlias) = 0;                                           // 100
    virtual ClassType* FindScriptClass(CName aName) = 0;                                                             // 108
    virtual EnumType* FindScriptEnum(CName aName) = 0;                                                               // 110
    virtual CName NativeNameToScriptAlias(CName aName) = 0;                                                          // 118
    virtual CName ScriptAliasToNativeName(CName aName) = 0;                                                          // 120
    virtual CString* GetStringConst(uint32_t aIndex) = 0;                                                            // 128 - Used by StringConst opcode (0x10)
    virtual void SetStringTable(DynArray<CString>& aStrings) = 0;                                                    // 130 - Called by script loader
    virtual ~ITypeSystem() = 0;                                                                                      // 138

#pragma region deprecated
    [[deprecated("Use 'FindType()' instead.")]]
    IType* GetType(CName aName)
    {
        return FindType(aName);
    }

    [[deprecated("Use 'FindClass()' instead.")]]
    ClassType* GetClass(CName aName)
    {
        return FindClass(aName);
    }
#pragma endregion
};
RED4EXT_ASSERT_SIZE(ITypeSystem, 0x8);

struct TypeSystemImpl : ITypeSystem
{
    static TypeSystemImpl* Get();

    using ITypeSystem::RegisterType;
    void RegisterType(IType* aType);

    std::atomic<bool> hasRegistered;                // 08
    HashMap<CName, IType*> typesByName;             // 10
    HashMap<uint64_t, IType*> typesByHash;          // 40
    HashMap<CName, uint64_t> typeHashesByName;      // 70
    HashMap<CName, Function*> globalFuncsByName;    // A0
    HashMap<uint64_t, Function*> globalFuncsByHash; // D0
    HashMap<void*, void*> unkF8;                    // F8
    DynArray<void*> unk130;                         // 130
    DynArray<void*> unk140;                         // 140
    HashMap<CName, CName> scriptNameToNativeName;   // 150
    HashMap<CName, CName> nativeNameToScriptName;   // 180
    DynArray<CString> strings;                      // 1B0 - Used by StringConst opcode (0x10)
    DynArray<void*> unk1C0;                         // 1C0
    DynArray<void*> unk1D0;                         // 1D0
    Mutex unk1E0;                                   // 1E0
    SharedSpinLock typesLock;                       // 208
    Mutex rttiRegistratorMutex;                     // 210
};
RED4EXT_ASSERT_SIZE(TypeSystemImpl, 0x238);
RED4EXT_ASSERT_OFFSET(TypeSystemImpl, hasRegistered, 0x08);
RED4EXT_ASSERT_OFFSET(TypeSystemImpl, typesByName, 0x10);
RED4EXT_ASSERT_OFFSET(TypeSystemImpl, globalFuncsByName, 0xA0);
RED4EXT_ASSERT_OFFSET(TypeSystemImpl, scriptNameToNativeName, 0x150);
RED4EXT_ASSERT_OFFSET(TypeSystemImpl, nativeNameToScriptName, 0x180);

struct RTTIRegistrator
{
    typedef void (*CallbackFunc)(void);

    [[deprecated("Use 'AddRegisterCallback()' and `AddPostRegisterCallback()` instead.")]]
    static void Add(CallbackFunc aRegFunc, CallbackFunc aPostRegFunc, bool aUnused = true);

    /**
     * @brief Returns the next unique identifier used for RTTI types.
     * @return The unique identifier.
     *
     * @note Every type in RED4 has a unique identifier assigned to it, reusing the IDs manually might lead to a crash,
     * thus we are using the game's counter to create our own types.
     */
    static const uint32_t GetNextId();
};
RED4EXT_ASSERT_SIZE(RTTIRegistrator, 0x01);

} // namespace rtti
using RTTISystem = rtti::TypeSystemImpl;
using CRTTISystem [[deprecated("Use 'rtti::TypeSystemImpl' instead.")]] = rtti::TypeSystemImpl;
using RTTIRegistrator = rtti::RTTIRegistrator;
} // namespace RED4ext

#ifdef RED4EXT_HEADER_ONLY
#include <RED4ext/RTTISystem-inl.hpp>
#endif
