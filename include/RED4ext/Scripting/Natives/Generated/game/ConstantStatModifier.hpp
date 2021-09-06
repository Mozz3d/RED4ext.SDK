#pragma once

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/StatModifierBase.hpp>

namespace RED4ext
{
namespace game { 
struct ConstantStatModifier : game::StatModifierBase
{
    static constexpr const char* NAME = "gameConstantStatModifier";
    static constexpr const char* ALIAS = NAME;

    uint8_t unk10[0x18 - 0x10]; // 10
};
RED4EXT_ASSERT_SIZE(ConstantStatModifier, 0x18);
} // namespace game
} // namespace RED4ext