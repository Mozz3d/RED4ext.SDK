#pragma once

#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/rend/Chunk.hpp>
#include <RED4ext/Scripting/Natives/Vector4.hpp>
#include <RED4ext/Rendering/RenderData.hpp>

#include <cstdint>

namespace RED4ext
{
struct RenderResourceUploadSource
{
	ResourcePath path;
	void* unk08;
};

struct IRenderResource : IRenderData
{
    using AllocatorType = Memory::RenderResourcesAllocator;

    virtual ~IRenderResource() = default;
    virtual CName GetResourceName() = 0;
    virtual char** sub_20() = 0;
    virtual int32_t sub_28() = 0;
};
RED4EXT_ASSERT_SIZE(IRenderResource, 0x10);

struct CRenderMesh : IRenderResource
{
    using AllocatorType = Memory::RenderMeshAllocator;

    virtual ~CRenderMesh() = default;

    Vector4 quantizationScale;    // 10
    Vector4 quantizationOffset    // 20
    uint32_t vertexBufferID;      // 30 - GpuApi buffer ID
    uint32_t indexBufferID;       // 34
    uint8_t unk38[0xa0 - 0x38];   // 38
    DynArray<rend::Chunk> chunks; // A0
    uint8_t unkB0[0x158 - 0xb0];  // B0
};
RED4EXT_ASSERT_SIZE(CRenderMesh, 0x158);
RED4EXT_ASSERT_OFFSET(CRenderMesh, quantization, 0x10);
RED4EXT_ASSERT_OFFSET(CRenderMesh, vertexBufferID, 0x30);
RED4EXT_ASSERT_OFFSET(CRenderMesh, indexBufferID, 0x34);
RED4EXT_ASSERT_OFFSET(CRenderMesh, chunks, 0xA0);

struct CRenderMorphTargetMesh : CRenderMesh
{
    virtual ~CRenderMorphTargetMesh() = default;

    uint8_t unk158[0x160 - 0x158]; // 158
    uint32_t baseVertexBufferID;   // 160
    uint8_t unk164[0x168 - 0x164]; // 164
};
RED4EXT_ASSERT_SIZE(CRenderMorphTargetMesh, 0x168);
RED4EXT_ASSERT_OFFSET(CRenderMorphTargetMesh, baseVertexBufferID, 0x160);

struct CRenderMaterialSetup : IRenderResource
{
    uint8_t unk10[0x48 - 0x10];
};
RED4EXT_ASSERT_SIZE(CRenderMaterialSetup, 0x48);

struct CRenderMaterialParameters : IRenderResource
{
    uint8_t unk10[0x128 - 0x10];
};
RED4EXT_ASSERT_SIZE(CRenderMaterialParameters, 0x128);

struct CRenderMaterial : CRenderMaterialParameters
{
    uint8_t unk128[0xb00 - 0x128];
};
RED4EXT_ASSERT_SIZE(CRenderMaterial, 0xb00);

struct CRenderHairProfile : IRenderResource
{
    uint8_t unk10[0x40 - 0x10];
};

RED4EXT_ASSERT_SIZE(CRenderHairProfile, 0x40);
} // namespace RED4ext
