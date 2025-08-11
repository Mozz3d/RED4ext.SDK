#pragma once

#include <RED4ext/Rendering/RenderResource.hpp>

namespace RED4ext::rend
{

struct FoliageProfileData
{
    float cutoffAlphaMinMip = 0.45;
    float cutoffAlphaMaxMip = 0.12;
    float billboardCutoffAlpha = 0.6;
    float aoScale = 0.5;
    float terrainBlendScale = 0.2;
    float terrainBlendBias = 0.f;
    float billboardDepthScale = 1.f;
    float preserveOriginalColor = 0.f;
    float billboardRoughnessBias = 0.1;
    TRenderPtr<IRenderResource> colorGradient;
    float colorGradientWeight = 0.f;
    float colorGradientDarkenWeight = 0.f;
}

} // RED4ext::rend
