## Project ----------------------------------------------------------------------------- #
cmake_minimum_required (VERSION 3.10)

## Variables --------------------------------------------------------------------------- #

## Configuration -------------------- -------------------------------------------------- #

## Includes ---------------------------------------------------------------------------- #
set (INCLUDES_APP
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
)

set (INCLUDES_STM32
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc/STM32
    PARENT_SCOPE
)

## Include submodules ------------------------------------------------------------------ #

## Sources ----------------------------------------------------------------------------- #
set (SOURCES_STM32
    Src/STM32/Startup/startup_stm32f303retx.s
    Src/STM32/stm32f3xx_hal_msp.c
    Src/STM32/stm32f3xx_it.c
    Src/STM32/syscalls.c
    Src/STM32/sysmem.c
    Src/STM32/system_stm32f3xx.c
)

set (SOURCES
    Src/main.c
    Src/Graphics/graphics_fonts.c
    Src/Graphics/graphics.c
    Src/Display/ssd1306.c
    Src/Display/ssd1306_io.c
)

## Jobs -------------------------------------------------------------------------------- #
add_executable (${PROJECT_NAME} ${SOURCES} ${SOURCES_STM32})
add_dependencies(${PROJECT_NAME} STM32_CMSIS STM32_HAL)
target_link_libraries (${PROJECT_NAME} STM32_CMSIS STM32_HAL)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES_STM32} ${INCLUDES_APP})

add_custom_command (TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_SIZE} ARGS ${PROJECT_NAME}
    COMMAND mkdir -p ${CMAKE_SOURCE_DIR}/.BuildArtifacts & rm -f ${CMAKE_SOURCE_DIR}/.BuildArtifacts/*
    COMMAND ${CMAKE_OBJCOPY} ARGS -O binary ${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/.BuildArtifacts/${PROJECT_NAME}.bin
    COMMAND ${CMAKE_OBJCOPY} ARGS -O ihex ${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/.BuildArtifacts/${PROJECT_NAME}.hex
    COMMAND cp ${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/.BuildArtifacts/${PROJECT_NAME}.elf
    COMMAND cp ${PROJECT_NAME}.map ${CMAKE_SOURCE_DIR}/.BuildArtifacts
)
