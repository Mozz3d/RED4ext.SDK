#pragma once
#pragma message("WARNING: 'RED4ext/Scripting/CProperty.hpp' is deprecated. Please use 'RED4ext/RTTI/Property.hpp' instead.")

#include <RED4ext/RTTI/Property.hpp>

namespace RED4ext
{
using CProperty = [[deprecated("Use 'rtti::Property' instead.")]] = rtti::Property;
} // namespace RED4ext
