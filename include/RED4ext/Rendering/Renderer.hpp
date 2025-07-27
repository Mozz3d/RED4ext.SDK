#pragma once

#include <RED4ext/Rendering/RenderResource.hpp>
#include <RED4ext/Rendering/RenderScene.hpp>
#include <RED4ext/Rendering/RenderProxy.hpp>
#include <RED4ext/Scripting/Natives/Generated/IRenderResourceBlob.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/GradientEntry.hpp>

struct HairProfileRenderData
{
	uint32_t sampleCount;
	//DynArray<rend::GradientEntry> gradientEntriesID;
	//DynArray<rend::GradientEntry> gradientEntriesRootToTip;
};

struct RenderBatcher
{
	uint8_t unk00[0xb74349];
};
RED4EXT_ASSERT_SIZE(RenderBatcher, 0xb74349);


struct IRenderCommandHandler
{
	virtual ~IRenderCommandHandler() = default;													 // 00
	virtual void sub_08() = 0;																	 // 08
	virtual void sub_10() = 0;																	 // 10
	virtual void sub_18() = 0;																	 // 18
	virtual void sub_20() = 0;																	 // 20
	virtual void RegisterCamera() = 0;															 // 28
	virtual void UnregisterCamera() = 0;														 // 30
	virtual void AddCameraDependency() = 0;														 // 38
	virtual void RemoveCameraDependency() = 0;													 // 40
	virtual void UpdateCameraDate() = 0;														 // 48
	virtual void MarkCameraCut() = 0;															 // 50
	virtual void sub_58() = 0;																	 // 58
	virtual void sub_60() = 0;																	 // 60
	virtual void sub_68() = 0;																	 // 68
	virtual void sub_70() = 0;																	 // 70
	virtual void sub_78() = 0;																	 // 78
	virtual void sub_80() = 0;																	 // 80
	virtual void UpdateSecondaryRefPoint() = 0;													 // 88
	virtual void UpdateLocalShadowsInfo() = 0;													 // 90
	virtual void UpdateHitProxyID() = 0;														 // 98
	virtual void AppendVertexShaderCustomSlotParams() = 0;										 // A0
	virtual void SetSelectionFlag() = 0;														 // A8
	virtual void sub_b0() = 0;																	 // B0
	virtual void TakeScreenshot(void* a1) = 0;													 // B8
	virtual void TakeScreenshot() = 0;															 // C0
	virtual void ToggleContinuousScreenshot() = 0;												 // C8
	virtual void ReloadReflectionProbe() = 0;													 // D0
	virtual void ScreenFadeOut(TRenderPtr<IRenderScene>& aScene, const Color& aColor, float aFadeTime) = 0; // D8
	virtual void ScreenFadeIn() = 0;																	    // E0
	virtual void ChangeSceneForcedLOD(TRenderPtr<IRenderScene>& aScene, int32_t aLOD) = 0;				    // E8
	virtual void SetProxyDissolveVisibility() = 0;															// F0
	virtual void DisableClusteredProxyInstances() = 0;														// F8
	virtual void ForceLODForProxy() = 0;																	// 100
	virtual void ForceLODForProxies() = 0;																    // 108
	virtual void LODLevelScalesForProxy() = 0;													 // 110
	virtual void SuspendRendering() = 0;														 // 118
	virtual void ResumeRendering() = 0;															 // 120
	virtual void GamePaused() = 0;																 // 128
	virtual void GameUnpaused() = 0;															 // 130
	virtual void HandleResizeEvent() = 0;														 // 138
	virtual void SetAutoFoliageRuntimeMap() = 0;												 // 140
	virtual void sub_148() = 0;																	 // 148
	virtual void AddWindImpulseShapes() = 0;													 // 150
	virtual void SetInteriorMapCellData() = 0;													 // 158
	virtual void SetAutohideDistanceNear() = 0;													 // 160
	virtual void sub_168() = 0;																	 // 168
	virtual void UpdateFogVolumeEffectContext() = 0;											 // 170
	virtual void UpdateMaterialParameterEffectContext() = 0;									 // 178
	virtual void UpdateLightParameterEffectContext() = 0;										 // 180
	virtual void UpdateColorGradeEffectContext() = 0;											 // 188
	virtual void UpdateMotionBlurScaleEffectContext() = 0;										 // 190
	virtual void UpdateExposureScaleEffectContext() = 0;										 // 198
	virtual void UpdateTonemappingEffectContext() = 0;											 // 1A0
	virtual void SaveTonemappingEffectContext() = 0;											 // 1A8
	virtual void RestoreTonemappingEffectContext() = 0;											 // 1B0
	virtual void UpdateChromaticAberrationEffectContext() = 0;									 // 1B8
	virtual void UpdateBloomnEffectContext() = 0;												 // 1C0
	virtual void UpdateVignetteEffectContext() = 0;												 // 1C8
	virtual void UpdateColorGradeV2EffectContext() = 0;											 // 1D0
	virtual void UpdateEmissiveEffectContext() = 0;												 // 1D8
	virtual void UpdateFilmGrainEffectContext() = 0;											 // 1E0
	virtual void UpdateWeaponPlaneBlurEffectContext() = 0;										 // 1E8
	virtual void UpdateFOVEffectContext() = 0;													 // 1F0
	virtual void UpdateDataMoshEffectContext() = 0;												 // 1F8
	virtual void UpdateDecalEffectContext() = 0;												 // 200
	virtual void UpdateVehicleParams() = 0;														 // 208
	virtual void UpdateFlatTireParams() = 0;													 // 210
	virtual void UpdateClothMeshData() = 0;														 // 218
	virtual void UpdateDestructionRegionsEffectContext() = 0;									 // 220
	virtual void Add_SetDismembermentData() = 0;												 // 228
	virtual void SetRainData() = 0;																 // 230
	virtual void SuspendParticles() = 0;														 // 238
	virtual void ResumeParticles() = 0;															 // 240
	virtual void SetMaterialParameterOverrides() = 0;											 // 248
	virtual void UpdateMaterialData() = 0;														 // 250
	virtual void ApplyMorphTargetWeights() = 0;													 // 258
	virtual void UnloadMorphData() = 0;															 // 260
	virtual void UpdateLightFlickerParams() = 0;												 // 268
	virtual void ResizeDynamicTexture() = 0;													 // 270
	virtual void PushDrawBuffer() = 0;							                                 // 278
	virtual void ForceRelitGlobalProbe() = 0;													 // 280
	virtual void ForceRelitLocalProbes() = 0;													 // 288
	virtual void NotifyPlayerInsideVehicle() = 0;												 // 290
	virtual void DisableAllGameplayEffects() = 0;												 // 298
	virtual void ToggleGameplayEffect() = 0;													 // 2A0
	virtual void SetGameplayEffectParameters() = 0;												 // 2A8
	virtual void SetVisionModeHighlight() = 0;													 // 2B0
	virtual void SetVisionModeScanning() = 0;													 // 2B8
	virtual void EnforceScreenSpaceReflectionsUberQuality() = 0;								 // 2C0
	virtual void AddOccluderToScene() = 0;														 // 2C8
	virtual void AddOccludersToScene() = 0;														 // 2D0
	virtual void RemoveOccluderFromScene() = 0;													 // 2D8
	virtual void RemoveOccludersFromScene() = 0;												 // 2E0
	virtual void UpdateOccluder() = 0;															 // 2E8
	virtual void SetVideoToRender() = 0;														 // 2F0
	virtual void FlushTextureGrabs() = 0;														 // 2F8
	virtual void sub_300() = 0;																	 // 300
	virtual void SetMeshChunkMask() = 0;														 // 308
	virtual void SetIndexBufferOverride() = 0;													 // 310
	virtual void SetMeshMaterialOverlay() = 0;													 // 318
	virtual void ResetSceneCustomData() = 0;													 // 320
	virtual void NotifyPhotoModeCharacterMovement() = 0;										 // 328
	virtual void OnPhotoModeOpened() = 0;														 // 330
};

struct CRenderCommandHandler : IRenderCommandHandler
{	
	uint8_t unk08[0xcb8 - 0x08]; // 08
};
RED4EXT_ASSERT_SIZE(CRenderCommandHandler, 0xcb8);

struct RenderHairProfileHandler
{
	using AllocatorType = Memory::RenderDataAllocator;

	uint8_t unk00[0x30 - 0x00];
};
RED4EXT_ASSERT_SIZE(RenderHairProfileHandler, 0x30);

struct SurfaceCache
{
	using AllocatorType = Memory::SurfaceCacheAllocator;

	uint8_t unk00[0xf0 - 0x00];
};
RED4EXT_ASSERT_SIZE(SurfaceCache, 0xf0);

struct IRenderInterface
{
	virtual ~IRenderInterface() = 0;
	virtual void* sub_08(void* a1) = 0;
	virtual void sub_10(void* a1) = 0;
	virtual bool sub_18() { return true; }
	virtual void sub_20() {}
	virtual void* sub_28() { return nullptr; }
	virtual void* sub_30() { return nullptr; }
	virtual void sub_38() {}
	virtual void* sub_40() { return nullptr; }
	virtual void sub_48() {}
	virtual void sub_50() {}
	virtual void sub_58() {}
	virtual float sub_60() { return 0.033333335f; }
	virtual bool sub_68() { return false; }
	virtual void sub_70() {}
	virtual void sub_78() {}
	virtual void sub_80() {}
	virtual void sub_88() {}
	virtual void sub_90() {}
	virtual void sub_98() {}
	virtual void sub_a0() {}
	virtual void sub_a8() {}
	virtual void sub_b0() {}
	virtual void sub_b8() {}
	virtual void sub_c0() {}
	virtual void sub_c8() {}
	virtual void sub_d0() {}
	virtual void sub_d8() {}
	virtual bool sub_e0() { return false; }
	virtual void* sub_e8() = 0;
	virtual void* sub_f0() = 0;
	virtual void sub_f8() {}
	virtual TRenderPtr<IRenderResource>* CreateAndUploadRenderMesh(TRenderPtr<IRenderResource>& aOutResource, RenderResourceUploadSource& aUploadSrc, Handle<IRenderResourceBlob> aResourceBlob) { return {}; }
	virtual TRenderPtr<IRenderResource>* CreateAndUploadRenderTexture(TRenderPtr<IRenderResource>& aOutResource, RenderResourceUploadSource& aUploadSrc, Handle<IRenderResourceBlob> aResourceBlob, void* a5) { return {}; } // 108
	virtual void* sub_110() { return {}; }
	virtual void sub_118() {}
	virtual void sub_120() {}
	virtual void* sub_128() { return {}; }
	virtual void sub_130() {}
	virtual void* sub_138() { return {}; }
	virtual void sub_140() {}
	virtual void* sub_148() { return {}; }
	virtual void sub_150() {}
	virtual void* sub_158() { return {}; }
	virtual void sub_160() {}
	virtual TRenderPtr<IRenderResource>* CreateAndUploadRenderHairProfile(TRenderPtr<IRenderResource>& aOutResource, HairProfileRenderData& aProfileData) { return {}; }
	virtual void sub_170() {}
	virtual void* sub_178() { return {}; }
	virtual void sub_180() {}
	virtual void* sub_188() { return {}; }
	virtual void sub_190() {}
	virtual void* sub_198() { return {}; }
	virtual void sub_1a0() {}
	virtual void* sub_1a8() { return {}; }
	virtual void sub_1b0() {}
	virtual void* sub_1b8() { return {}; }
	virtual void* sub_1c0() { return {}; }
	virtual void* sub_1c8() { return {}; }
	virtual void* sub_1d0() { return {}; }
	virtual void* sub_1d8() { return nullptr; }
	virtual void sub_1e0() {}
	virtual void* sub_1e8() { return {}; }
	virtual void* sub_1f0() { return {}; }
	virtual void* sub_1f8() = 0;
	virtual void sub_200() {}
	virtual void sub_208() {}
	virtual void sub_210() {}
	virtual void sub_218() {}
	virtual void sub_220() {}
	virtual void* CreateDebugRenderer(void* a1, uint32_t a2, uint32_t a3) { return nullptr; }
	virtual TRenderPtr<IRenderScene>* CreateRenderScene(TRenderPtr<IRenderScene>& aOutScene) { return {}; }
	virtual TRenderPtr<IRenderProxy>* CreateRenderProxy(TRenderPtr<IRenderProxy>& aOutProxy, void* a2, void* a3) { return {}; }
	virtual void* sub_240() { return {}; }
	virtual void* sub_248() { return {}; }
	virtual void* sub_250() { return {}; }
	virtual void* sub_258() { return {}; }
	virtual void* sub_260() { return {}; }
	virtual void* sub_268() { return {}; }
	virtual bool sub_270() { return false; }
	virtual void sub_278() = 0;
	virtual bool sub_280() { return false; }
	virtual bool sub_288() { return false; }
	virtual bool sub_290() { return false; }
	virtual void sub_298() {}
	virtual void sub_2a0() {}
	virtual void sub_2a8() {}
	virtual void sub_2b0() {}
	virtual void sub_2b8() {}
	virtual void sub_2c0() {}
	virtual bool sub_2c8() { return false; }
	virtual void sub_2d0() {}
	virtual void sub_2d8() {}
	virtual uint64_t sub_2e0() { return 0; }
	virtual void* sub_2e8() { return nullptr; }
	virtual uint64_t sub_2f0() { return 0; }
	virtual uint64_t sub_2f8() { return 0; }
	virtual uint64_t sub_300() { return 0; }
	virtual void* sub_308() { return nullptr; }
	virtual void sub_310() {}
	virtual void* sub_318() { return nullptr; }
	virtual uint32_t sub_320() { return 1; }
	virtual uint32_t sub_328() { return 1; }
	virtual bool sub_330() { return false; }
	virtual bool sub_338() { return true; }
	virtual bool sub_340() { return true; }
	virtual void sub_348() {}
	virtual bool sub_350() { return true; }
	virtual bool sub_358() { return true; }
	virtual bool sub_360() { return true; }
	virtual bool sub_368() { return true; }
	virtual bool sub_370() { return true; }
	virtual void sub_378() {}
	virtual bool sub_380() { return false; }
	virtual bool sub_388() { return true; }
	virtual float sub_390() { return 1.f; }
	virtual void sub_398() = 0;
	virtual void* sub_3a0() { return nullptr; }
	virtual void sub_3a8() = 0;
	virtual void sub_3b0() = 0;
	virtual bool sub_3b8() { return false; }
	virtual void sub_3c0() {}
	virtual void sub_3c8() {}
	virtual bool sub_3d0() { return false; }
	virtual CRenderCommandHandler* GetRenderCommandHandler() { return nullptr; }
	virtual void* sub_3e0() = 0;
	virtual void* sub_3e8() { return {}; }
	virtual void sub_3f0() {}

	uint8_t unk00[0x48 - 0x08]; // 08
};
RED4EXT_ASSERT_SIZE(IRenderInterface, 0x48);

struct CRenderInterface : IRenderInterface
{
	uint8_t unk00[0x70 - 0x48]; // 48
	CRenderCommandHandler* renderCommandHandler; // 70
	uint8_t unk78[0xF8 - 0x78]; // 78
	UniquePtr<RenderHairProfileHandler> renderHairProfileHandler; // F8
	uint8_t unk100[0x4638 - 0x100]; // 100
	UniquePtr<SurfaceCache> surfaceCache;
	uint8_t unk4640[0x4dd0 - 0x4640]; // 4640
};
RED4EXT_ASSERT_SIZE(CRenderInterface, 0x4dd0);

RED4EXT_INLINE CRenderInterface* GetRenderer()
{
	static const UniversalRelocPtr<CRenderInterface*> renderInterface(1931610229);
	return renderInterface;
}
