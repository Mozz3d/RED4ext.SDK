#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Handle.hpp>
#include <RED4ext/Scripting/Natives/Generated/scn/IInterruptManager_Operation.hpp>

namespace RED4ext
{
namespace scn { struct IReturnCondition; }

namespace scn
{
struct OverrideReturnConditions_Operation : scn::IInterruptManager_Operation
{
    static constexpr const char* NAME = "scnOverrideReturnConditions_Operation";
    static constexpr const char* ALIAS = NAME;

    DynArray<Handle<scn::IReturnCondition>> returnConditions; // 30
};
RED4EXT_ASSERT_SIZE(OverrideReturnConditions_Operation, 0x40);
} // namespace scn
using scnOverrideReturnConditions_Operation = scn::OverrideReturnConditions_Operation;
} // namespace RED4ext

// clang-format on
