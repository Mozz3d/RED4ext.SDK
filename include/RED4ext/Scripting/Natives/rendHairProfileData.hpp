#pragma once

#include <RED4ext/Scripting/Natives/Generated/rend/GradientData.hpp>

namespace RED4ext::rend
{

struct HairProfileData
{
    uint32_t sampleCount;
    DynArray<rend::GradientEntry> gradientEntriesID;
	DynArray<rend::GradientEntry> gradientEntriesRootToTip;
}

} // RED4ext::rend
