#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/NativeTypes.hpp>
#include <RED4ext/Scripting/Natives/Generated/CResource.hpp>

namespace RED4ext
{
struct CResource;

namespace res
{
struct ResourceSnapshot : CResource
{
    static constexpr const char* NAME = "resResourceSnapshot";
    static constexpr const char* ALIAS = NAME;

    DynArray<RaRef<CResource>> resources; // 40
};
RED4EXT_ASSERT_SIZE(ResourceSnapshot, 0x50);
} // namespace res
using resResourceSnapshot = res::ResourceSnapshot;
} // namespace RED4ext

// clang-format on
