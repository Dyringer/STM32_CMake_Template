## Project ----------------------------------------------------------------------------- #
cmake_minimum_required (VERSION 3.10)
project (STM32_Device C ASM)

## Variables --------------------------------------------------------------------------- #
set (PROJECT_NAME   "STM32_Device")

## Configuration -------------------- -------------------------------------------------- #
set (CMAKE_C_FLAGS_DEBUG     ${ARCHFLAGS_DEBUG})
set (CMAKE_C_FLAGS_RELEASE   ${ARCHFLAGS_RELEASE})
set (CMAKE_C_FLAGS           ${ARCHFLAGS_C})
set (CMAKE_CXX_FLAGS         ${ARCHFLAGS_CXX})

## Includes ---------------------------------------------------------------------------- #

## Include submodules ------------------------------------------------------------------ #
add_subdirectory(Application)
add_subdirectory(Drivers)