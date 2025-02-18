#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/ISerializable.hpp>
#include <RED4ext/NativeTypes.hpp>

namespace RED4ext
{
namespace quest { struct IBaseCondition; }
namespace scn { struct IInterruptionOperation; }
namespace scn { struct SceneResource; }

namespace world
{
struct ConversationData : ISerializable
{
    static constexpr const char* NAME = "worldConversationData";
    static constexpr const char* ALIAS = NAME;

    RaRef<scn::SceneResource> sceneFilename; // 30
    Handle<quest::IBaseCondition> condition; // 38
    DynArray<Handle<scn::IInterruptionOperation>> interruptionOperations; // 48
    bool ignoreLocalLimit; // 58
    bool ignoreGlobalLimit; // 59
    uint8_t unk5A[0x60 - 0x5A]; // 5A
};
RED4EXT_ASSERT_SIZE(ConversationData, 0x60);
} // namespace world
using worldConversationData = world::ConversationData;
} // namespace RED4ext

// clang-format on
