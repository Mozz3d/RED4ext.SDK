cmake_minimum_required(VERSION 3.21)

include(CMakeDependentOption)

project(RED4ext.SDK LANGUAGES CXX)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
elseif(CMAKE_CXX_STANDARD LESS 20)
  message(FATAL_ERROR "RED4ext.SDK requires C++20 or higher.")
endif()

if(PROJECT_IS_TOP_LEVEL)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

option(RED4EXT_HEADER_ONLY "Use the header only version of the library." OFF)
option(RED4EXT_BUILD_EXAMPLES "Build plugin examples." OFF)
option(RED4EXT_EXTRA_WARNINGS "Enable extra warnings." OFF)
option(RED4EXT_TREAT_WARNINGS_AS_ERRORS "Treat compiler warnings as errors." OFF)

cmake_dependent_option(RED4EXT_USE_PCH "Use precompiled headers to speed up compilation time." OFF "NOT RED4EXT_HEADER_ONLY" OFF)

if(RED4EXT_EXTRA_WARNINGS)
  if(MSVC)
    add_compile_options(/W4)
  else()
    add_compile_options(-Wall -Wextra)
  endif()
endif()

if(RED4EXT_TREAT_WARNINGS_AS_ERRORS)
  if(MSVC)
    add_compile_options(/WX)
  else()
    add_compile_options(-Werror)
  endif()
endif()

set(RED4EXT_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB_RECURSE RED4EXT_HEADERS "${RED4EXT_INCLUDE_DIR}/*.hpp")

if(RED4EXT_HEADER_ONLY)
  add_library(RED4ext.SDK INTERFACE)
  target_include_directories(RED4ext.SDK INTERFACE ${RED4EXT_INCLUDE_DIR})
else()
  file(GLOB_RECURSE RED4EXT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

  source_group(CMake REGULAR_EXPRESSION cmake_pch.*)
  source_group(TREE "${RED4EXT_INCLUDE_DIR}/RED4ext" FILES ${RED4EXT_HEADERS})
  source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/src" FILES ${RED4EXT_SOURCES})

  add_library(RED4ext.SDK STATIC ${RED4EXT_HEADERS} ${RED4EXT_SOURCES})

  target_include_directories(RED4ext.SDK PUBLIC ${RED4EXT_INCLUDE_DIR})
  target_compile_definitions(RED4ext.SDK PUBLIC RED4EXT_STATIC_LIB)

  if(COMMAND target_precompile_headers AND RED4EXT_USE_PCH)
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/pch.hpp.in" "${PROJECT_BINARY_DIR}/red4ext_pch.hpp" @ONLY)
    target_precompile_headers(RED4ext.SDK PRIVATE "${PROJECT_BINARY_DIR}/red4ext_pch.hpp")
  endif()
endif()

add_library(RED4ext::SDK ALIAS RED4ext.SDK)

if(RED4EXT_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()