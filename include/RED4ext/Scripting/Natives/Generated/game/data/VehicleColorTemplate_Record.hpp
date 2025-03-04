#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Scripting/Natives/Generated/game/data/TweakDBRecord.hpp>

namespace RED4ext
{
namespace game::data
{
struct VehicleColorTemplate_Record : game::data::TweakDBRecord
{
    static constexpr const char* NAME = "gamedataVehicleColorTemplate_Record";
    static constexpr const char* ALIAS = "VehicleColorTemplate_Record";

    uint8_t unk48[0xD0 - 0x48]; // 48
};
RED4EXT_ASSERT_SIZE(VehicleColorTemplate_Record, 0xD0);
} // namespace game::data
using gamedataVehicleColorTemplate_Record = game::data::VehicleColorTemplate_Record;
using VehicleColorTemplate_Record = game::data::VehicleColorTemplate_Record;
} // namespace RED4ext

// clang-format on
