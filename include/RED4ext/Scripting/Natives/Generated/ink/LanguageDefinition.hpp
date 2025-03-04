#pragma once

// clang-format off

// This file is generated from the Game's Reflection data

#include <cstdint>
#include <RED4ext/Common.hpp>
#include <RED4ext/CName.hpp>
#include <RED4ext/Containers/DynArray.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/ETextDirection.hpp>
#include <RED4ext/Scripting/Natives/Generated/ink/LanguageFont.hpp>

namespace RED4ext
{
namespace ink
{
struct LanguageDefinition
{
    static constexpr const char* NAME = "inkLanguageDefinition";
    static constexpr const char* ALIAS = NAME;

    CName languageCode; // 00
    CName isoScriptCode; // 08
    ink::ETextDirection textDirection; // 10
    uint8_t unk14[0x18 - 0x14]; // 14
    DynArray<ink::LanguageFont> fonts; // 18
};
RED4EXT_ASSERT_SIZE(LanguageDefinition, 0x28);
} // namespace ink
using inkLanguageDefinition = ink::LanguageDefinition;
} // namespace RED4ext

// clang-format on
