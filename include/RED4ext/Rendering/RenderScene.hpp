#pragma once

#include <RED4ext/Rendering/RenderData.hpp>

struct IRenderScene : IRenderData
{
	virtual ~IRenderScene() = default;
	virtual uint64_t sub_18(uint64_t a1) = 0;
	virtual void* sub_20(uint32_t* a1) = 0;
	virtual void sub_28() = 0;
	virtual uint8_t sub_30() = 0;
	virtual uint64_t sub_38() = 0;
	virtual void sub_40(uint8_t a1) = 0;
	virtual uint64_t sub_48() = 0;
	virtual void sub_50() = 0;
	virtual void sub_58(int32_t a1) = 0;
	virtual uint32_t sub_60() = 0;
	virtual void sub_68(uint32_t a1) = 0;
	virtual void sub_70(float a1) = 0;
	virtual uint32_t sub_78() = 0;
	virtual uint8_t sub_80(RenderDataPtr<>* a1) = 0;
};

struct CRenderScene : IRenderScene
{
	uint8_t unk08[0x267b80 - 0x08]; // 00
};
