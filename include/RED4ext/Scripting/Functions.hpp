#pragma once
#pragma message("WARNING: 'RED4ext/Scripting/Functions.hpp' is deprecated. Please use 'RED4ext/RTTI/Function.hpp' instead.")

#include <RED4ext/RTTI/Function.hpp>

namespace RED4ext
{
struct [[deprecated("Use 'rtti::Function' instead.")]] CBaseFunction : rtti::Function
{
};
struct [[deprecated("Use 'rtti::NativeGlobalFunction' instead.")]] CGlobalFunction : rtti::NativeGlobalFunction
{
};
struct [[deprecated("Use 'rtti::NativeMemberFunction' instead.")]] CClassFunction : rtti::NativeMemberFunction
{
};
struct [[deprecated("Use 'rtti::NativeMemberFunction' instead.")]] CClassStaticFunction : rtti::NativeMemberFunction
{
};
struct [[deprecated("Use 'rtti::ScriptedMemberFunction' instead.")]] CScriptedFunction : rtti::ScriptedMemberFunction
{
};
} // namespace RED4ext
