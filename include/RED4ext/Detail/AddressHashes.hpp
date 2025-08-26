#pragma once

#include <cstdint>

#include <RED4ext/Hashing/FNV1a.hpp>

// clang-format off
namespace RED4ext::Detail::AddressHashes
{
#pragma region CBaseFunction
constexpr std::uint32_t CBaseFunction_Handlers = 0x5A7D28A9;
constexpr std::uint32_t CBaseFunction_ExecuteScripted = 0xE1F920D6;
constexpr std::uint32_t CBaseFunction_ExecuteNative = 0xE1321AEB;
constexpr std::uint32_t CBaseFunction_InternalExecute = 0x1817231D;
#pragma endregion

#pragma region CBaseRTTIType
constexpr std::uint32_t CBaseRTTIType_sub_80 = 0xE46F169E;
constexpr std::uint32_t CBaseRTTIType_sub_88 = 0x15BE1744;
constexpr std::uint32_t CBaseRTTIType_sub_90 = 0xA45935A1;
constexpr std::uint32_t CBaseRTTIType_sub_98 = 0xAEA91F1D;
constexpr std::uint32_t CBaseRTTIType_sub_A0 = 0x8ED61BC2;
#pragma endregion

#pragma region CBitfield
constexpr std::uint32_t CBitfield_Unserialize = 0xA6981914;
constexpr std::uint32_t CBitfield_ToString = 0x54231404;
constexpr std::uint32_t CBitfield_FromString = 0xA09B15A8;
#pragma endregion

#pragma region CClass
constexpr std::uint32_t CClass_Unserialize = 0xE4AA0CAD;
constexpr std::uint32_t CClass_ToString = 0x65293F06;
constexpr std::uint32_t CClass_sub_80 = 0x11D11B0C;
constexpr std::uint32_t CClass_sub_88 = 0x4BDF1BB2;
constexpr std::uint32_t CClass_sub_90 = 0xA26D374E;
constexpr std::uint32_t CClass_sub_98 = 0x48C020CA;
constexpr std::uint32_t CClass_sub_A0 = 0x15F21D6F;
constexpr std::uint32_t CClass_sub_B0 = 0xA0911974;
constexpr std::uint32_t CClass_sub_C0 = 3523744305UL;
constexpr std::uint32_t CClass_GetMaxAlignment = 0xD14E1230;
constexpr std::uint32_t CClass_sub_D0 = 0x37750EBF;
constexpr std::uint32_t CClass_CreateInstance = 0x5A800F1D;
constexpr std::uint32_t CClass_GetProperty = 0x8F031512;
constexpr std::uint32_t CClass_GetProperties = 1652956141UL;
constexpr std::uint32_t CClass_ClearScriptedData = 0x31F20E93;
constexpr std::uint32_t CClass_InitializeProperties = 2257327441UL;
constexpr std::uint32_t CClass_AssignDefaultValuesToProperties = 0x97DF1590;
#pragma endregion

#pragma region CClassFunction
constexpr std::uint32_t CClassFunction_ctor = 0x602D29F3;
#pragma endregion

#pragma region CClassStaticFunction
constexpr std::uint32_t CClassStaticFunction_ctor = 2920426135UL;
#pragma endregion

#pragma region CEnum
constexpr std::uint32_t CEnum_Unserialize = 0x40D317A6;
constexpr std::uint32_t CEnum_ToString = 0x41A1296;
constexpr std::uint32_t CEnum_FromString = 0x21CA1EC1;
#pragma endregion

#pragma region CGameEngine
constexpr std::uint32_t CGameEngine = 0x97F209D6;
#pragma endregion

#pragma region CGlobalFunction
constexpr std::uint32_t CGlobalFunction_ctor = 0xFA6B24D0;
#pragma endregion

#pragma region CNamePool
constexpr std::uint32_t CNamePool_AddCstr = 0xA00C9B;
constexpr std::uint32_t CNamePool_AddCString = 0xFFD61709;
constexpr std::uint32_t CNamePool_AddPair = 0xD9840BD8;
constexpr std::uint32_t CNamePool_Get = 0x68DF07DC;
#pragma endregion

#pragma region CommandListContext
constexpr std::uint32_t GetFreeCommandList = 1926836641UL;
constexpr std::uint32_t CommandListContext_dtor = 4228123904UL;
constexpr std::uint32_t CommandListContext_AddPendingBarrier = 2814122829UL;
constexpr std::uint32_t CommandListContext_Close = 1163138096UL;
constexpr std::uint32_t CommandListContext_FlushPendingBarriers = 2786924000UL;
#pragma endregion

#pragma region CRTTIRegistrator
constexpr std::uint32_t CRTTIRegistrator_RTTIAsyncId = 0xDDBD19E8;
#pragma endregion

#pragma region CRTTIScriptReferenceType
constexpr std::uint32_t CRTTIScriptReferenceType_ctor = 0xCB8A115C;
constexpr std::uint32_t CRTTIScriptReferenceType_Set = 0x22EE172F;
#pragma endregion

#pragma region CRTTISystem
constexpr std::uint32_t CRTTISystem_Get = 0x4A610F64;
#pragma endregion

#pragma region CStack
constexpr std::uint32_t CStack_vtbl = 0x349A0EE1;
#pragma endregion

#pragma region CString
constexpr std::uint32_t CString_ctor_str = 0xC81F0AAB;
constexpr std::uint32_t CString_ctor_span = 0x7B210877;
constexpr std::uint32_t CString_copy = 0xE8B40B51;
constexpr std::uint32_t CString_dtor = 0x5405072C;
#pragma endregion

#pragma region DeviceData
constexpr std::uint32_t g_DeviceData = 1239944840UL;
#pragma endregion

#pragma region DynArray
constexpr std::uint32_t DynArray_Realloc = 0x7AA013D2;
#pragma endregion

#pragma region D3D12MA
constexpr std::uint32_t Allocator_CreateResource = 2508272872UL;
#pragma endregion

#pragma region FundamentalTypes
constexpr std::uint32_t FundamentalTypeBool_GetName = 3880784410UL;
constexpr std::uint32_t FundamentalTypeInt8_GetName = 3817869809UL;
constexpr std::uint32_t FundamentalTypeUint8_GetName = 4184740454UL;
constexpr std::uint32_t FundamentalTypeInt16_GetName = 4068872736UL;
constexpr std::uint32_t FundamentalTypeUint16_GetName = 149426837UL;
constexpr std::uint32_t FundamentalTypeInt32_GetName = 4065858078UL;
constexpr std::uint32_t FundamentalTypeUint32_GetName = 146412179UL;
constexpr std::uint32_t FundamentalTypeFloat_GetName = 4227469956UL;
constexpr std::uint32_t FundamentalTypeDouble_GetName = 280433385UL;
constexpr std::uint32_t FundamentalTypeInt64_GetName = 4073919011UL;
constexpr std::uint32_t FundamentalTypeUint64_GetName = 154473112UL;

constexpr std::uint32_t FundamentalTypeBool_GetRefName = 569905975UL;
constexpr std::uint32_t FundamentalTypeInt8_GetRefName = 506991374UL;
constexpr std::uint32_t FundamentalTypeUint8_GetRefName = 892539779UL;
constexpr std::uint32_t FundamentalTypeInt16_GetRefName = 776672061UL;
constexpr std::uint32_t FundamentalTypeUint16_GetRefName = 1169888178UL;
constexpr std::uint32_t FundamentalTypeInt32_GetRefName = 773657403UL;
constexpr std::uint32_t FundamentalTypeUint32_GetRefName = 1166873520UL;
constexpr std::uint32_t FundamentalTypeFloat_GetRefName = 935269281UL;
constexpr std::uint32_t FundamentalTypeDouble_GetRefName = 1300894726UL;
constexpr std::uint32_t FundamentalTypeInt64_GetRefName = 781718336UL;
constexpr std::uint32_t FundamentalTypeUint64_GetRefName = 1174934453UL;

constexpr std::uint32_t FundamentalTypeBool_ToString = 325981961UL;
constexpr std::uint32_t FundamentalTypeInt8_ToString = 4186248864UL;
constexpr std::uint32_t FundamentalTypeUint8_ToString = 4188608161UL;
constexpr std::uint32_t FundamentalTypeInt16_ToString = 4190967458UL;
constexpr std::uint32_t FundamentalTypeUint16_ToString = 4193326755UL;
constexpr std::uint32_t FundamentalTypeInt32_ToString = 4195686052UL;
constexpr std::uint32_t FundamentalTypeUint32_ToString = 4198045349UL;
constexpr std::uint32_t FundamentalTypeFloat_ToString = 4207482537UL;
constexpr std::uint32_t FundamentalTypeDouble_ToString = 4209841834UL;
constexpr std::uint32_t FundamentalTypeInt64_ToString = 316544773UL;
constexpr std::uint32_t FundamentalTypeUint64_ToString = 318904070UL;

constexpr std::uint32_t FundamentalTypeBool_FromString = 1782847661UL;
constexpr std::uint32_t FundamentalTypeInt8_FromString = 1328552004UL;
constexpr std::uint32_t FundamentalTypeUint8_FromString = 1330976837UL;
constexpr std::uint32_t FundamentalTypeInt16_FromString = 1333401670UL;
constexpr std::uint32_t FundamentalTypeUint16_FromString = 1335826503UL;
constexpr std::uint32_t FundamentalTypeInt32_FromString = 1338251336UL;
constexpr std::uint32_t FundamentalTypeUint32_FromString = 1340676169UL;
constexpr std::uint32_t FundamentalTypeFloat_FromString = 1350375501UL;
constexpr std::uint32_t FundamentalTypeDouble_FromString = 1352800334UL;
constexpr std::uint32_t FundamentalTypeInt64_FromString = 1773148329UL;
constexpr std::uint32_t FundamentalTypeUint64_FromString = 1775573162UL;

constexpr std::uint32_t FundamentalTypeBool_ReadValue = 932461408UL;
constexpr std::uint32_t FundamentalTypeInt8_ReadValue = 4100471543UL;
constexpr std::uint32_t FundamentalTypeUint8_ReadValue = 4109384440UL;
constexpr std::uint32_t FundamentalTypeInt16_ReadValue = 4118297337UL;
constexpr std::uint32_t FundamentalTypeUint16_ReadValue = 4127210234UL;
constexpr std::uint32_t FundamentalTypeInt32_ReadValue = 4136123131UL;
constexpr std::uint32_t FundamentalTypeUint32_ReadValue = 4145036028UL;
constexpr std::uint32_t FundamentalTypeFloat_ReadValue = 4180687616UL;
constexpr std::uint32_t FundamentalTypeDouble_ReadValue = 4189600513UL;
constexpr std::uint32_t FundamentalTypeInt64_ReadValue = 896809820UL;
constexpr std::uint32_t FundamentalTypeUint64_ReadValue = 905722717UL;

constexpr std::uint32_t FundamentalTypeBool_WriteValue = 3962774748UL;
constexpr std::uint32_t FundamentalTypeInt8_WriteValue = 3247187059UL;
constexpr std::uint32_t FundamentalTypeUint8_WriteValue = 3252102260UL;
constexpr std::uint32_t FundamentalTypeInt16_WriteValue = 3257017461UL;
constexpr std::uint32_t FundamentalTypeUint16_WriteValue = 3261932662UL;
constexpr std::uint32_t FundamentalTypeInt32_WriteValue = 3266847863UL;
constexpr std::uint32_t FundamentalTypeUint32_WriteValue = 3271763064UL;
constexpr std::uint32_t FundamentalTypeFloat_WriteValue = 3291423868UL;
constexpr std::uint32_t FundamentalTypeDouble_WriteValue = 3296339069UL;
constexpr std::uint32_t FundamentalTypeInt64_WriteValue = 3943113944UL;
constexpr std::uint32_t FundamentalTypeUint64_WriteValue = 3948029145UL;

template<typename T>
struct FundamentalType;

template<> struct FundamentalType<bool> {
    static constexpr std::uint32_t GetName = FundamentalTypeBool_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeBool_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeBool_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeBool_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeBool_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeBool_WriteValue;
};
template<> struct FundamentalType<std::int8_t> {
    static constexpr std::uint32_t GetName = FundamentalTypeInt8_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeInt8_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeInt8_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeInt8_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeInt8_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeInt8_WriteValue;
};
template<> struct FundamentalType<std::uint8_t> {
    static constexpr std::uint32_t GetName = FundamentalTypeUint8_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeUint8_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeUint8_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeUint8_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeUint8_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeUint8_WriteValue;
};
template<> struct FundamentalType<std::int16_t> {
    static constexpr std::uint32_t GetName = FundamentalTypeInt16_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeInt16_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeInt16_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeInt16_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeInt16_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeInt16_WriteValue;
};
template<> struct FundamentalType<std::uint16_t> {
    static constexpr std::uint32_t GetName = FundamentalTypeUint16_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeUint16_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeUint16_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeUint16_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeUint16_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeUint16_WriteValue;
};
template<> struct FundamentalType<std::int32_t> {
    static constexpr std::uint32_t GetName = FundamentalTypeInt32_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeInt32_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeInt32_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeInt32_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeInt32_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeInt32_WriteValue;
};
template<> struct FundamentalType<std::uint32_t> {
    static constexpr std::uint32_t GetName = FundamentalTypeUint32_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeUint32_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeUint32_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeUint32_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeUint32_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeUint32_WriteValue;
};
template<> struct FundamentalType<float> {
    static constexpr std::uint32_t GetName = FundamentalTypeFloat_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeFloat_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeFloat_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeFloat_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeFloat_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeFloat_WriteValue;
};
template<> struct FundamentalType<double> {
    static constexpr std::uint32_t GetName = FundamentalTypeDouble_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeDouble_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeFloat_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeDouble_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeDouble_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeDouble_WriteValue;
};
template<> struct FundamentalType<std::int64_t> {
    static constexpr std::uint32_t GetName = FundamentalTypeInt64_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeInt64_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeInt64_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeInt64_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeInt64_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeInt64_WriteValue;
};
template<> struct FundamentalType<std::uint64_t> {
    static constexpr std::uint32_t GetName = FundamentalTypeUint64_GetName;
    static constexpr std::uint32_t GetRefName = FundamentalTypeUint64_GetRefName;
    static constexpr std::uint32_t ToString = FundamentalTypeUint64_ToString;
    static constexpr std::uint32_t FromString = FundamentalTypeUint64_FromString;
    static constexpr std::uint32_t ReadValue = FundamentalTypeUint64_ReadValue;
    static constexpr std::uint32_t WriteValue = FundamentalTypeUint64_WriteValue;
};
#pragma endregion

#pragma region Handle
constexpr std::uint32_t Handle_ctor = 0xBA0C115D;
constexpr std::uint32_t Handle_DecWeakRef = 0x333B1404;
#pragma endregion

#pragma region IRenderProxy
constexpr std::uint32_t IRenderProxy_sub_00 = 302583262UL;
constexpr std::uint32_t IRenderProxy_sub_08 = 3505328647UL;
constexpr std::uint32_t IRenderProxy_sub_18 = 2756580845UL;
constexpr std::uint32_t IRenderProxy_sub_58 = 2462126272UL;
constexpr std::uint32_t IRenderProxy_sub_60 = 3491501770UL;
constexpr std::uint32_t IRenderProxy_sub_78 = 2542474580UL;
constexpr std::uint32_t IRenderProxy_sub_80 = 510274732UL;
constexpr std::uint32_t IRenderProxy_sub_88 = 3724941976UL;
constexpr std::uint32_t IRenderProxy_sub_90 = 1894391003UL;
constexpr std::uint32_t IRenderProxy_sub_98 = 3516862860UL;
constexpr std::uint32_t IRenderProxy_sub_A8 = 4096926792UL;
constexpr std::uint32_t IRenderProxy_sub_B0 = 1468405902UL;
#pragma endregion

#pragma region IScriptable
constexpr std::uint32_t IScriptable_sub_D8 = 0xF8E41DDF;
constexpr std::uint32_t IScriptable_DestructValueHolder = 0x3521331;
#pragma endregion

#pragma region ISerializable
constexpr std::uint32_t ISerializable_sub_30 = 0x6D63649;
constexpr std::uint32_t ISerializable_sub_40 = 0x88B30FF9;
constexpr std::uint32_t ISerializable_sub_78 = 0xA1D93993;
constexpr std::uint32_t ISerializable_sub_A0 = 0xED221B32;
constexpr std::uint32_t ISerializable_sub_C0 = 0x80201C35;
constexpr std::uint32_t ISerializable_Counter = 2630817091;
#pragma endregion

#pragma region JobDispatcher
constexpr std::uint32_t JobDispatcher = 1508445968UL;
constexpr std::uint32_t JobDispatcher_DispatchJob = 2621709954UL;
#pragma endregion

#pragma region JobHandle
constexpr std::uint32_t JobHandle_dtor = 0x9E480A2E;
constexpr std::uint32_t JobHandle_Join = 0x9C9C097C;
#pragma endregion

#pragma region JobInternalHandle
constexpr std::uint32_t JobInternalHandle_Acquire = 0x6EFF1BD2;
#pragma endregion

#pragma region JobQueue
constexpr std::uint32_t JobQueue_ctor_FromGroup = 0xE750D4B;
constexpr std::uint32_t JobQueue_ctor_FromParams = 0x82BD14F8;
constexpr std::uint32_t JobQueue_dtor = 0x5AF4077C;
constexpr std::uint32_t JobQueue_Capture = 0x41D12C4;
constexpr std::uint32_t JobQueue_SyncWait = 3651996672UL;
#pragma endregion

#pragma region Memory
constexpr std::uint32_t Memory_Vault = 0x1B530DEC;
constexpr std::uint32_t Memory_Vault_Alloc = 0x902A14E0;
constexpr std::uint32_t Memory_Vault_AllocAligned = 0x516917DD;
constexpr std::uint32_t Memory_Vault_Realloc = 0x770A17AC;
constexpr std::uint32_t Memory_Vault_ReallocAligned = 0x56961AA9;
constexpr std::uint32_t Memory_Vault_Free = 0x33421332;
constexpr std::uint32_t Memory_Vault_Unk1 = 0x19EC1367;
constexpr std::uint32_t Memory_PoolStorage_OOM = 0xD54F163A;
#pragma endregion

#pragma region OpcodeHandlers
constexpr std::uint32_t OpcodeHandlers = 0x39532858;
#pragma endregion

#pragma region ObjectPackageExtractor
constexpr std::uint32_t ObjectPackageExtractor_Initialize = 2318998714;
constexpr std::uint32_t ObjectPackageExtractor_ExtractSync = 2038372664;
constexpr std::uint32_t ObjectPackageExtractor_ExtractAsync = 3819248393;
#pragma endregion

#pragma region ObjectPackageReader
constexpr std::uint32_t ObjectPackageReader_ctor = 3628731410;
constexpr std::uint32_t ObjectPackageReader_OnReadHeader = 1632836642;
constexpr std::uint32_t ObjectPackageReader_ReadHeader = 1285757088;
#pragma endregion

#pragma region BasePackageReader
constexpr std::uint32_t BasePackageReader_ReadHeader = 3410956665;
#pragma endregion

#pragma region ResourceDepot
constexpr std::uint32_t ResourceDepot = 0x659A0FC7;
#pragma endregion

#pragma region ResourceLoader
constexpr std::uint32_t ResourceLoader = 0x783C1034;
constexpr std::uint32_t ResourceLoader_FindTokenFast = 0xC86F39B7;
constexpr std::uint32_t ResourceLoader_IssueLoadingRequest = 2365013187;
constexpr std::uint32_t ResourceLoader_IssueLoadingRequestByPath = 1250309504;
#pragma endregion

#pragma region ResourceReference
constexpr std::uint32_t ResourceReference_Load = 0xEB0DA9;
constexpr std::uint32_t ResourceReference_Fetch = 0xB69D158E;
constexpr std::uint32_t ResourceReference_Reset = 0x2308246B;
#pragma endregion

#pragma region ResourceToken
constexpr std::uint32_t ResourceToken_dtor = 0x9A5F0A0D;
constexpr std::uint32_t ResourceToken_Fetch = 0x8C0918CA;
constexpr std::uint32_t ResourceToken_OnLoaded = 0xEB4B25AB;
constexpr std::uint32_t ResourceToken_CancelUnk38 = 0xF6E20CE6;
constexpr std::uint32_t ResourceToken_DestructUnk38 = 0x95831FEE;
#pragma endregion

#pragma region TTypedClass
constexpr std::uint32_t TTypedClass_IsEqual = 0x58630EE8;
#pragma endregion

#pragma region TweakDB
constexpr std::uint32_t TweakDB_Get = 0x36800DE4;
constexpr std::uint32_t TweakDB_CreateRecord = 0x3201127A;
#pragma endregion

#pragma region UpdateRegistrar
constexpr std::uint32_t UpdateRegistrar_RegisterGroupUpdate = 0xFD914605;
constexpr std::uint32_t UpdateRegistrar_RegisterBucketUpdate = 0x192F4EA2;
#pragma endregion

#pragma region DeferredDataBuffer
constexpr std::uint32_t DeferredDataBuffer_LoadAsync = 4125893577;
constexpr std::uint32_t DeferredDataBuffer_LoadRefAsync = 1459046115;
#pragma endregion

#pragma region LaunchParameters
constexpr std::uint32_t LaunchParameters = 677908004;
#pragma endregion
}
// clang-format on
