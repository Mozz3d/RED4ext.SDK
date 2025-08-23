#pragma once
#pragma message("WARNING: 'RED4ext/Scripting/Functions.hpp' is deprecated. Please use 'RED4ext/RTTI/Function.hpp' instead.")

#include <RED4ext/RTTI/Function.hpp>

namespace RED4ext
{
using CBaseFunction [[deprecated("Use 'rtti::Function' instead.")]] = rtti::Function;
using CGlobalFunction [[deprecated("Use 'rtti::NativeGlobalFunction' instead.")]] = rtti::NativeGlobalFunction;
using CClassFunction [[deprecated("Use 'rtti::NativeMemberFunction' instead.")]] = rtti::NativeMemberFunction;
using CClassStaticFunction [[deprecated("Use 'rtti::NativeMemberFunction' instead.")]] = rtti::NativeMemberFunction;
using CScriptedFunction [[deprecated("Use 'rtti::ScriptedMemberFunction' instead.")]] = rtti::ScriptedMemberFunction;
} // namespace RED4ext
