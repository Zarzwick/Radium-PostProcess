#ifndef POSTPROCESSPLUGIN_MACROS_HPP
#define POSTPROCESSPLUGIN_MACROS_HPP

#include <Core/CoreMacros.hpp>

/// Defines the correct macro to export dll symbols.
#if defined LightPath_EXPORTS
#    define PP_PLUGIN_API DLL_EXPORT
#else
#    define PP_PLUGIN_API DLL_IMPORT
#endif

#endif
