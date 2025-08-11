#pragma once

#include <RED4ext/Scripting/Natives/Generated/rend/GradientData.hpp>

namespace RED4ext::rend
{

struct GradientData
{
    DynArray<GradientEntry> entries;
}

} // RED4ext::rend
