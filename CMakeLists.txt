cmake_minimum_required(VERSION 3.0)
project(PostProcessPlugin)
set(POSTPROCESS PostProcess)

if (APPLE)
    cmake_policy(SET CMP0042 NEW)
endif(APPLE)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Qt stuff
find_package(Qt5Core    REQUIRED)
find_package(Qt5Widgets REQUIRED)
add_definitions(${Qt5Core_DEFINITIONS})
add_definitions(${Qt5Widgets_DEFINITIONS})
set(Qt5_LIBRARIES ${Qt5Core_LIBRARIES} ${Qt5Widgets_LIBRARIES})

# Radium Stuff
find_package(Radium REQUIRED)

# Build options options.
option(RADIUM_WITH_DOUBLE_PRECISION "Use double precision" OFF)
option(RADIUM_WITH_OMP              "Use OpenMP" ON)
option(RADIUM_WITH_TEXTURES         "Compile Radium enabling texture loading stuff" ON)
option(RADIUM_WITH_PROFILING        "Enable functions profiling." OFF)
option(RADIUM_WARNINGS_AS_ERRORS    "Treat compiler warning as errors" OFF)
option(RADIUM_FORCE_ASSERTS         "Enable asserts regardless of build type" OFF)
option(RADIUM_FAST_MATH             "Enable Fast Math optimizations in Release Mode (ignored with MVSC)" OFF)

# use Radium's common compilation options
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${RADIUM_ROOT_DIR}/cmake)
# perhaps not a good idea of including all the stuff from CompileFlags
# FIXME : get the correct flags (openmp, float precision, ... instead of the default
include (CompileFlags)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RADIUM_BUNDLE_DIRECTORY}/${CMAKE_BUILD_TYPE}/bin)
set(EXECUTABLE_OUTPUT_PATH         ${RADIUM_BUNDLE_DIRECTORY}/${CMAKE_BUILD_TYPE}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${RADIUM_PLUGIN_OUTPUT_PATH})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${RADIUM_PLUGIN_OUTPUT_PATH})

message("${POSTPROCESS} output path : ${RADIUM_PLUGIN_OUTPUT_PATH}")

if (NOT CMAKE_PREFIX_PATH)
  set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR})
endif()


# Win32 stuff
if (MSVC OR MSVC_IDE)
    # Copy libs / targets in the correct directories
    if ("${CMAKE_GENERATOR}" STREQUAL "NMake Makefiles")
        set(PDB_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    else()
        foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
            string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
            set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
            set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
        endforeach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    endif()
endif(MSVC OR MSVC_IDE)


file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE headers src/*.hpp)
file(GLOB_RECURSE inlines src/*.inl)
file(GLOB_RECURSE app_uis  src/*.ui)

qt5_wrap_ui(app_uis_moc ${app_uis})
# message("App UI are ${app_uis} and mocs are ${app_uis_moc} !")
message("CMAKE_CURRENT_BINARY_DIR : ${CMAKE_CURRENT_BINARY_DIR}  !")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


# Include look up directories
include_directories(
    src/
    ${CMAKE_CURRENT_BINARY_DIR} # MOC
    ${Qt5Core_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${RADIUM_INCLUDE_DIRS}
   )

# Our library project uses these sources and headers.
add_library(
    ${POSTPROCESS} SHARED
    ${sources}
    ${headers}
    ${inlines}
    ${app_uis}
)

target_compile_definitions(${POSTPROCESS} PRIVATE "-D${POSTPROCESS}_EXPORTS")

target_link_libraries(
                   ${POSTPROCESS}
                   ${RADIUM_LIBRARIES}              # Radium libs
                   ${GLBINDING_LIBRARIES}           # Radium dep
                   ${Qt5_LIBRARIES}                 # the Qt beast
                   fftw3
               )
