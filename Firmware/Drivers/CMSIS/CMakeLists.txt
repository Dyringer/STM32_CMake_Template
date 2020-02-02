## Project ----------------------------------------------------------------------------- #
cmake_minimum_required (VERSION 3.10)
project (STM32_CMSIS)

## Variables --------------------------------------------------------------------------- #
set (LIBRARY_NAME   "STM32_CMSIS")

## Configuration -------------------- -------------------------------------------------- #

## Include submodules ------------------------------------------------------------------ #

## Includes ---------------------------------------------------------------------------- #
set (INCLUDES_CMSIS
	${CMAKE_CURRENT_SOURCE_DIR}/Include
	${CMAKE_CURRENT_SOURCE_DIR}/Device/ST/STM32F3xx/Include
)

## Sources ----------------------------------------------------------------------------- #

## Jobs -------------------------------------------------------------------------------- #
add_library(${LIBRARY_NAME} INTERFACE)
target_include_directories (${LIBRARY_NAME} INTERFACE ${INCLUDES_CMSIS})


