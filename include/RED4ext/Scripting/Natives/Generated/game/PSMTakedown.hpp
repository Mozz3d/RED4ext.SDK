#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
namespace RED4ext
{
namespace game {
enum class PSMTakedown : uint32_t
{
    Default = 0,
    EnteringGrapple = 1,
    Grapple = 2,
    Leap = 3,
    Takedown = 4,
    Any = 4294967295,
};
} // namespace game
using gamePSMTakedown = game::PSMTakedown;
} // namespace RED4ext

// clang-format on
