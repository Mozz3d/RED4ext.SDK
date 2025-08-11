#pragma once

struct IRenderCommandHandler
{
	virtual ~IRenderCommandHandler() = default;													                   // 00
	virtual void RetirePendingResources(void* a1, uint8_t a2) = 0;						                           // 08
	virtual void FrameTick(void* a1, uint8_t a2) = 0;								                               // 10
	virtual void FlushRenderScene(void* a1) = 0;												                   // 18
	virtual void sub_20(void* a1) = 0;															                   // 20
	virtual void RegisterCamera(void* a1, uint64_t a2, void* a3, uint64_t a4) = 0;				                   // 28
	virtual void UnregisterCamera(void* a1, uint64_t a2) = 0;									                   // 30
	virtual void AddCameraDependency(void* a1, uint64_t a2, uint64_t a3) = 0;					                   // 38
	virtual void RemoveCameraDependency(void* a1, uint64_t a2, uint64_t a3) = 0;				                   // 40
	virtual void UpdateCameraDate(void* a1, uint64_t a2, uint64_t a3) = 0;						                   // 48
	virtual void MarkCameraCut(void* a1, uint64_t a2) = 0;										                   // 50
	virtual void sub_58(void* a1, uint64_t a2) = 0;												                   // 58
	virtual void sub_60(void* a1, uint64_t a2) = 0;																   // 60
	virtual void sub_68(void* a1, uint64_t a2) = 0;																   // 68
	virtual void sub_70(void* a1, uint64_t a2) = 0;																   // 70
	virtual void sub_78(void* a1, uint64_t a2) = 0;																   // 78
	virtual void sub_80(void* a1, uint64_t a2) = 0;																   // 80
	virtual void UpdateSecondaryRefPoint(void* a1, void* a2) = 0;												   // 88
	virtual void UpdateLocalShadowsInfo(void* a1, void* a2, uint8_t a3, uint8_t a4) = 0;	    				   // 90
	virtual void UpdateHitProxyID(void* a1) = 0;														           // 98
	virtual void AppendVertexShaderCustomSlotParams(void* a1, void* a2) = 0;									   // A0
	virtual void SetSelectionFlag(void* a1, void* a2, uint8_t a3, uint8_t a4) = 0;								   // A8
	virtual void sub_b0() {};																	                   // B0
	virtual void TakeScreenshot(uint64_t a1, uint64_t a2, uint32_t a3, uint64_t a4, uint64_t a5, uint32_t a6) = 0; // B8
	virtual void TakeScreenshot(uint64_t a1, uint64_t a2, uint32_t a3, uint32_t a4, uint64_t a5, uint32_t a6) = 0; // C0
	virtual void ToggleContinuousScreenshot(uint8_t a1, uint32_t a2) = 0;										   // C8
	virtual void ReloadReflectionProbe(void* a1, uint64_t a2) = 0;												   // D0
	virtual void ScreenFadeOut(void* a1, void* a2, uint32_t a3) = 0;                                               // D8
	virtual void ScreenFadeIn(void* a1, uint32_t a2) = 0;														   // E0
	virtual void ChangeSceneForcedLOD(void* a1, uint32_t a2) = 0;				                                   // E8
	virtual void SetProxyDissolveVisibility(void* a1, uint8_t a2, uint8_t a3) = 0;								   // F0
	virtual void DisableClusteredProxyInstances(void* a1, uint64_t a2) = 0;										   // F8
	virtual void ForceLODForProxy(void* a1, uint8_t a2) = 0;													   // 100
	virtual void ForceLODForProxies(uint64_t a1, uint8_t a2) = 0;												   // 108
	virtual void LODLevelScalesForProxy(void* a1, uint8_t a2) = 0;												   // 110
	virtual void SuspendRendering() = 0;														                   // 118
	virtual void ResumeRendering() = 0;															                   // 120
	virtual void GamePaused() = 0;																                   // 128
	virtual void GameUnpaused() = 0;															                   // 130
	virtual void HandleResizeEvent(uint32_t a1, uint32_t a2) = 0;												   // 138
	virtual void SetAutoFoliageRuntimeMap(void* a1, void* a2) = 0;												   // 140
	virtual void sub_148(void* a1, uint32_t a2, uint32_t a3, uint32_t a4) = 0;									   // 148
	virtual void AddWindImpulseShapes(void* a1, uint64_t a2, uint64_t a3) = 0;									   // 150
	virtual void SetInteriorMapCellData(void* a1, uint64_t a2, void* a3, uint8_t a4) = 0;						   // 158
	virtual void SetAutohideDistanceNear(void* a1, uint32_t a2) = 0;											   // 160
	virtual void UpdateParticleEffectContext(void* a1, void* a2) = 0;									           // 168
	virtual void UpdateFogVolumeEffectContext(void* a1, void* a2) = 0;											   // 170
	virtual void UpdateMaterialParameterEffectContext(void* a1) = 0;									           // 178
	virtual void UpdateLightParameterEffectContext(void* a1, void* a2) = 0;										   // 180
	virtual void UpdateColorGradeEffectContext() = 0;											                   // 188
	virtual void UpdateMotionBlurScaleEffectContext(uint32_t a1) = 0;										       // 190
	virtual void UpdateExposureScaleEffectContext(void* a1) = 0;										           // 198
	virtual void UpdateTonemappingEffectContext(void* a1) = 0;											           // 1A0
	virtual void SaveTonemappingEffectContext() = 0;											                   // 1A8
	virtual void RestoreTonemappingEffectContext() = 0;											                   // 1B0
	virtual void UpdateChromaticAberrationEffectContext(void* a1) = 0;									           // 1B8
	virtual void UpdateBloomnEffectContext(void* a1) = 0;												           // 1C0
	virtual void UpdateVignetteEffectContext(void* a1) = 0;												           // 1C8
	virtual void UpdateColorGradeV2EffectContext() = 0;											                   // 1D0
	virtual void UpdateEmissiveEffectContext(void* a1) = 0;												           // 1D8
	virtual void UpdateFilmGrainEffectContext(void* a1) = 0;											           // 1E0
	virtual void UpdateWeaponPlaneBlurEffectContext(void* a1) = 0;										           // 1E8
	virtual void UpdateFOVEffectContext(void* a1, uint32_t a2) = 0;												   // 1F0
	virtual void UpdateDataMoshEffectContext(void* a1) = 0;												           // 1F8
	virtual void UpdateDecalEffectContext(void* a1, void* a2) = 0;												   // 200
	virtual void UpdateVehicleParams(void* a1, void* a2) = 0;													   // 208
	virtual void UpdateFlatTireParams(void* a1, void* a2) = 0;													   // 210
    virtual void UpdateSecondMultilayerParams(void* a1, uint64_t a2) = 0;										   // 218
    virtual void UpdateCrystalCoatParams(void* a1, uint64_t a2) = 0;									           // 220
    virtual void UpdateClothMeshData(void* a1, uint8_t a2, uint64_t a3, void* a4) = 0;					           // 228
    virtual void UpdateDestructionRegionsEffectContext(void* a1, void* a2) = 0;									   // 230
    virtual void Add_SetDismembermentData(void* a1, void* a2) = 0;												   // 238
	virtual void SetRainData(void* a1, void* a2) = 0;															   // 240
	virtual void SuspendParticles(void* a1) = 0;											                       // 248
	virtual void ResumeParticles(void* a1) = 0;														               // 250
	virtual void SetMaterialParameterOverrides(void* a1, uint64_t a2) = 0;										   // 258
	virtual void UpdateMaterialData(void* a1, uint64_t a2) = 0;													   // 260
	virtual void ApplyMorphTargetWeights(void* a1, uint64_t a2) = 0;											   // 268
	virtual void UnloadMorphData(void* a1) = 0;													                   // 270
	virtual void UpdateLightFlickerParams(void* a1, void* a2) = 0;							                       // 278
	virtual void ResizeDynamicTexture(void* a1, uint32_t a2, uint32_t a3, uint8_t a4) = 0;						   // 280
    virtual void sub_288(void* a1) = 0;													                           // 288
	virtual void ForceRelitGlobalProbe(void* a1) = 0;												               // 290
	virtual void ForceRelitLocalProbes(void* a1, void* a2, uint32_t a3) = 0;								       // 298
	virtual void NotifyPlayerInsideVehicle(void* a1, uint8_t a2) = 0;											   // 2A0
	virtual void DisableAllGameplayEffects() = 0;												                   // 2A8
	virtual void ToggleGameplayEffect(uint32_t a1, uint8_t a2) = 0;												   // 2B0
	virtual void SetGameplayEffectParameters(void* a1) = 0;												           // 2B8
    virtual void SetVisionModeHighlight(void* a1, void* a2, uint8_t a3, uint8_t a4, uint32_t a5, uint8_t a6) = 0;  // 2C0
	virtual void SetVisionModeScanning(void* a1, void* a2, uint8_t a3) = 0;										   // 2C8
	virtual void EnforceScreenSpaceReflectionsUberQuality(uint8_t a1) = 0;								           // 2D0
	virtual void AddOccluderToScene(void* a1, void* a2, void* a3) = 0;											   // 2D8
	virtual void AddOccludersToScene(void* a1, uint64_t a2) = 0;												   // 2E0
	virtual void RemoveOccluderFromScene(void* a1) = 0;													           // 2E8
	virtual void RemoveOccludersFromScene(void* a1) = 0;												           // 2F0
	virtual void UpdateOccluder(void* a1, void* a2) = 0;														   // 2F8
	virtual void SetVideoToRender(uint64_t a1, void* a2) = 0;													   // 300
    virtual void FlushTextureGrabs() = 0;														                   // 308
	virtual void sub_310() = 0;													                                   // 310
	virtual void SetMeshChunkMask(void* a1, uint64_t a2) = 0;													   // 318
	virtual void SetIndexBufferOverride(void* a1, void* a2) = 0;											       // 320
	virtual void sub_328(void* a1, void* a2, void* a3, uint8_t a4) = 0;								               // 328
	virtual void ResetSceneCustomData(void* a1) = 0;													           // 330
	virtual void NotifyPhotoModeCharacterMovement(void* a1, uint8_t a2) = 0;									   // 338
	virtual void OnPhotoModeOpened(uint8_t a1) = 0;									                               // 340
	virtual void OnPhotoModeUIVisibilityChanged(uint8_t a1) = 0;									               // 348
};

struct CRenderCommandHandler : IRenderCommandHandler
{	
	uint8_t unk08[0xcb8 - 0x08]; // 08
};
RED4EXT_ASSERT_SIZE(CRenderCommandHandler, 0xcb8);