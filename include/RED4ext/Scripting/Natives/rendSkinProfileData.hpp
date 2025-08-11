#pragma once

namespace RED4ext::rend
{

struct SkinProfileData
{
    float blurSize = 1.2;
    Color diffuse{ 122, 104, 72, 255 };
    Color falloff{ 255, 94, 76, 255};
    float roughness0 = 0.75;
    float rougness1 = 1.25;
    float lobeMix = 0.8;
}

} // RED4ext::rend
