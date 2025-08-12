#pragma once

#include <RED4ext/Memory/UniquePtr.hpp>
#include <RED4ext/Rendering/RenderResource.hpp>
#include <RED4ext/Rendering/RenderProxy.hpp>
#include <RED4ext/Rendering/RenderSkinning.hpp>
#include <RED4ext/Rendering/RenderScene.hpp>
#include <RED4ext/Rendering/RenderCommandHandler.hpp>
#include <RED4ext/Scripting/Natives/rendSkinProfileData.hpp>
#include <RED4ext/Scripting/Natives/rendHairProfileData.hpp>
#include <RED4ext/Scripting/Natives/rendGradientData.hpp>
#include <RED4ext/Scripting/Natives/rendTerrainMaterialData.hpp>
#include <RED4ext/Scripting/Natives/rendTextureRegionSet.hpp>
#include <RED4ext/Scripting/Natives/rendMultilayerSetupData.hpp>
#include <RED4ext/Scripting/Natives/Generated/IRenderResourceBlob.hpp>
#include <RED4ext/Scripting/Natives/Generated/STextureGroupSetup.hpp>

namespace RED4ext
{
struct SurfaceCache
{
	using AllocatorType = Memory::SurfaceCacheAllocator;

	uint8_t unk00[0xf0 - 0x00];
};
RED4EXT_ASSERT_SIZE(SurfaceCache, 0xf0);

struct IRender
{
	virtual ~IRender() = 0;
	virtual void* sub_08(void* a1) = 0;
	virtual void sub_10(void* a1) = 0;
	virtual bool Init() { return true; }
	virtual void Tick() {}
	virtual uint32_t GetLastTickCounter() { return 0; }
	virtual uint64_t sub_30() { return 0; }
	virtual void sub_38(uint64_t a1) {}
	virtual uint64_t sub_40() { return 0; }
	virtual void sub_48(uint64_t a1) {}
	virtual void sub_50() {}
	virtual void sub_58() {}
	virtual uint64_t sub_60() {}
	virtual void sub_68(uint64_t a1) {}
	virtual uint64_t sub_70() {}
	virtual void sub_78(uint64_t a1) {}
	virtual void sub_80() {}
	virtual void sub_88() {}
	virtual void sub_90(uint64_t a1) {}
	virtual uint64_t sub_98() {}
	virtual void sub_a0(uint32_t a1, uint32_t a2) {}
	virtual void sub_a8(uint32_t a1) {}
	virtual uint32_t GetLastFrameTime() {}
	virtual uint64_t sub_b8() {}
	virtual void sub_c0() {}
	virtual void Flush() {}
	virtual void Sync() {}
	virtual uint32_t RequestEvictOnNextSceneRender() {}
	virtual void sub_e0() {}
	virtual void sub_e8() {};
	virtual void LoadConfig() {};
	virtual void ReloadTextures() {}
	virtual void ReloadEngineShaders() {}
	virtual void FlushReloadSimpleShaders() {} // 108
	virtual void EnqueueReloadSimpleShaders() {}
	virtual void RecreatePlatformResources() {}
	virtual void sub_120() {}
	virtual void RelinkSimpleShaders() {}
	virtual bool sub_130() { return false; }
	virtual void* sub_138() { return nullptr; }
	virtual void sub_140() {}
	virtual void RequestResizeRenderSurfaces(uint32_t aWidth, uint32_t aHeight) {}

	virtual TRenderPtr<IRenderResource>* UploadBlobMesh(const SRenderDataSource& aSrc, Handle<IRenderResourceBlob> aBlob) { return nullptr; }
	virtual TRenderPtr<IRenderResource>* UploadBlobTexture(const SRenderDataSource& aSrc, Handle<IRenderResourceBlob> aBlob, const STextureGroupSetup& aTexGroupSetup) { return nullptr; }

	virtual void* sub_160(void* a1, void* a2) { return nullptr; }
	virtual void sub_168(void* a1, void* a2) {}
	virtual void sub_170(void* a1, void* a2) {}

	virtual TRenderPtr<IRenderResource>* UploadParticleEmitter(const char* aName, const Handle<IRenderResourceBlob>& aResourceBlob, const RenderEmitterDrawerData& aEmitterDrawer, const SDynamicDecalInitInfo& aDecalInitInfo) { return nullptr; }
	virtual void PrecacheParticleEmitter(const TRenderPtr<IRenderResource>& aEmitter, const TRenderPtr<IRenderResource>& aMaterial) {}
	
	virtual TRenderPtr<IRenderResource>* UploadMaterial(uint64_t a2, uint64_t a3, uint64_t a4, uint64_t a5) { return nullptr; }
	
	virtual void sub_190(void* a1, uint64_t a2, uint64_t a3) {}
	virtual TRenderPtr<IRenderResource>* sub_198(uint64_t a2, uint64_t a3, uint64_t a4) { return nullptr; }
	virtual void sub_1a0(void* a1, uint64_t a2) {}

	virtual TRenderPtr<IRenderResource>* UploadSkinProfile(const rend::SkinProfileData* aData) { return nullptr; }
	virtual void UpdateSkinProfile(const TRenderPtr<IRenderResource>& aSkinProfile, const rend::SkinProfileData* aData) {}

	virtual TRenderPtr<IRenderResource>* UploadHairProfile(const rend::HairProfileData* aData) { return nullptr; }
	virtual void UpdateHairProfile(const TRenderPtr<IRenderResource>& aHairProfile, const rend::HairProfileData* aData) {}

	virtual TRenderPtr<IRenderResource>* UploadGradient(const rend::GradientData* aData) { return nullptr; }
	virtual void UpdateGradient(const TRenderPtr<IRenderResource>& aGradient, const rend::GradientData* aData) {}

	virtual TRenderPtr<IRenderResource>* UploadTerrainSetup(const SRenderDataSource& aSrc, const rend::TerrainMaterialData& aData) { return nullptr; }
	virtual void UpdateTerrainSetup() {}

	virtual TRenderPtr<IRenderResource>* UploadFoliageProfile(const rend::FoliageProfileData* aData, uint64_t aHash) { return nullptr; }
	virtual void UpdateFoliageProfile(const TRenderPtr<IRenderResource>& aFoliageProfile, const rend::FoliageProfileData* aData) {}
	
	virtual TRenderPtr<IRenderResource>* UploadTextureRegionSet(const rend::TextureRegionSet* aData) { return nullptr; }
	virtual void UpdateTextureRegionSet() {}
	
	virtual TRenderPtr<IRenderResource>* UploadMultilayerSetup(const SRenderDataSource& aSrc, const rend::MultilayerSetupData& aData) { return nullptr; }
	virtual TRenderPtr<IRenderResource>* UploadMultilayerMask(const SRenderDataSource& aSrc, Handle<IRenderResourceBlob> aBlob) { return nullptr; }
	
	virtual void* sub_218(void* a1, void* a2, void* a3, void* a4, void* a5) { return nullptr; }
	virtual void* sub_220(void* a1, void* a2) { return nullptr; }
	virtual uint32_t sub_228(void* a1) { return 0; }
	virtual void sub_230(uint64_t a1, uint64_t a2) {}
	virtual void* sub_238(uint64_t a1, uint64_t a2, uint64_t a3) { return nullptr; }
	virtual void* sub_240(uint64_t a1, void* a2, uint64_t a3) { return nullptr; }
	virtual void* sub_248() {}
	virtual void sub_250() {}
	virtual void sub_258() {}
	virtual void sub_260() {}
	virtual uint64_t sub_268(void* a1) {}
	virtual void sub_270() {}
	virtual void sub_278(uint64_t a1, int32_t a2, int32_t a3) {};
	
	virtual TRenderPtr<IRenderScene>* CreateScene(uint32_t aSceneType /*persumably some enum type*/) { return nullptr; }
	virtual TRenderPtr<IRenderProxy>* CreateProxy(const RenderProxyInitInfo& aInitInfo, JobQueue* aJob) { return nullptr;}
	virtual TRenderPtr<IRenderResource>* CreateDynamicDecal(const SDynamicDecalInitInfo& aInitInfo) { return nullptr; }
	virtual TRenderPtr<IRenderSkinningData>* CreateSkinningBuffer(CName aName) { return nullptr; }
	virtual void* sub_2a0(void* a1, uint32_t a2) { return nullptr; }
	virtual void* sub_2a8(void* a1, uint32_t a2) { return nullptr; }
	virtual TRenderPtr<IRenderResource>* CreateDynamicTexture(const DynamicTextureDesc& aDesc) { return nullptr; }
	virtual TRenderPtr<IRenderResource>* CreateDynamicVolumeTexture(const DynamicVolumeTextureDesc& aDesc) { return nullptr; }
	
	virtual bool sub_2c0() { return false; }
	virtual void sub_2c8(uint32_t* a1, uint32_t a2) {}
	virtual bool sub_2d0() { return false; }
	virtual bool sub_2d8() { return false; }
	virtual bool sub_2e0() { return false; }
	virtual void sub_2e8(uint64_t a1) {}
	virtual void sub_2f0() {}
	virtual void sub_2f8() {}
	virtual void sub_300() {}
	virtual void sub_308(uint64_t a1, uint64_t a2, int32_t a3) {}
	virtual void sub_310() {}
	virtual bool sub_318() { return false; }
	virtual void sub_320() {}
	virtual void sub_328(uint64_t a1, bool a2) {}
	virtual uint32_t sub_330() { return 0; }
	virtual uint32_t sub_338() { return 0; }
	virtual uint32_t sub_340() { return 0; }
	virtual uint32_t sub_348() { return 0; }
	virtual float sub_350(float* a1, float* a2, float* a3) { return 0.f; }
	virtual uint32_t sub_358() { return 0; }
	virtual void sub_360() {}
	virtual void* sub_368() { return nullptr; }
	
	virtual int32_t GetMonitorCount() { return 1; }
	
	virtual uint8_t sub_378(uint32_t a1, uint8_t a2) { return 1; }
	virtual bool sub_380() { return false; }
	virtual bool sub_388() { return true; }
	virtual bool sub_390() { return true; }
	virtual void sub_398(uint8_t* a1, uint32_t* a2) {}
	virtual uint8_t sub_3a0() { return 1; }
	virtual uint8_t sub_3a8() { return 1; }
	virtual uint8_t sub_3b0() { return 1; }
	virtual uint8_t sub_3b8() { return 1; }
	virtual bool sub_3c0() { return true; }
	virtual uint8_t sub_3c8() { return 1; }
	virtual uint8_t sub_3d0() { return 1; }
	virtual bool sub_3d8(uint32_t* a1) { return true; }
	virtual bool sub_3e0(uint32_t* a1) { return true; }
	virtual void sub_3e8(void* a1) {}
	virtual bool sub_3f0() { return false; }
	virtual bool sub_3f8() { return false; }
	virtual uint8_t sub_400(uint32_t* a1) { return 1; }
	virtual float sub_408() { return 1.f; }
	virtual void sub_410(uint64_t a1, uint64_t a2) {}
	virtual int32_t sub_418() { return 0; }
	virtual void sub_420(void* a1, int32_t a2) {}
	virtual void sub_428(uint64_t a1, int32_t a2) {}
	virtual bool sub_430(int32_t a1, int32_t a2, int32_t* a3, int32_t* a4, uint32_t a5) { return false; }
	virtual void sub_438(uint32_t* a1, uint32_t* a2) {}
	virtual void sub_440(int32_t* a1) {}
	virtual bool sub_448() { return false; }
	virtual uint64_t sub_450() { return 0; }
	virtual void* sub_458(void* a1) {}
	virtual void* sub_460(void* a1, uint64_t a2) {}
	virtual void sub_468() {}

	uint8_t unk00[0x48 - 0x08]; // 08
};
RED4EXT_ASSERT_SIZE(IRender, 0x48);

struct CRenderInterface : IRender
{
	uint8_t unk00[0x70 - 0x48];					   // 48
	CRenderCommandHandler* m_renderCommandHandler; // 70
	uint8_t unk78[0x4638 - 0x78]; 				   // 78
	UniquePtr<SurfaceCache> m_surfaceCache; 	   // 4638
	uint8_t unk4640[0x4ca4 - 0x4640];			   // 4640
	uint32_t m_lastTickCounter;					   // 4CA4
	uint8_t unk4ca8[0x4df0 - 0x4ca8];			   // 4CA8
};
RED4EXT_ASSERT_SIZE(CRenderInterface, 0x4df0);

RED4EXT_INLINE CRenderInterface* GetRenderer()
{
	static const UniversalRelocPtr<CRenderInterface*> renderInterface(1931610229);
	return renderInterface;
}

} // namespace RED4ext
