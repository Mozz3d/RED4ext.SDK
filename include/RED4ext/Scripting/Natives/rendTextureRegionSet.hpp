#pragma once

#include <RED4ext/Scripting/Natives/Generated/rend/TextureRegion.hpp>

namespace RED4ext::rend
{
struct TextureRegionSet
{
    DynArray<rend::TextureRegion> regions;
}
} // namespace RED4ext::rend
