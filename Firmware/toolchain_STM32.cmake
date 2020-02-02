# System config
set (CMAKE_SYSTEM_NAME      "Generic")
set (CMAKE_SYSTEM_VERSION   1)

set (LINKER_PATH            ${CMAKE_CURRENT_SOURCE_DIR}/linker/STM32_debug.ld)

set (MCU_ARCH               cortex-m4)
set (MCU_FLOAT_ABI          hard)
set (MCU_FPU                fpv4-sp-d16)
set (MCU_TYPE               STM32F303xE)

# Cross compilation config
set (CMAKE_C_COMPILER       arm-none-eabi-gcc)
set (CMAKE_CXX_COMPILER     arm-none-eabi-g++)
set (CMAKE_LINKER           arm-none-eabi-ld)
set (CMAKE_OBJCOPY          arm-none-eabi-objcopy)
set (CMAKE_AR               arm-none-eabi-gcc-ar)
set (CMAKE_NM               arm-none-eabi-gcc-nm)
set (CMAKE_RANLIB           arm-none-eabi-gcc-ranlib)
set (CMAKE_SIZE             arm-none-eabi-size)

set (COMMON_FLAGS
    "-mthumb \
    -mfloat-abi=${MCU_FLOAT_ABI} \
    -DUSE_HAL_DRIVER \
    -D${MCU_TYPE} \
    -mcpu=${MCU_ARCH} \
    -ffunction-sections \
    -fdata-sections \
    --specs=nano.specs \
    --specs=nosys.specs"
)

if (MCU_FLOAT_ABI STREQUAL hard)
    set(COMMON_FLAGS "${COMMON_FLAGS} -mfpu=${MCU_FPU}")
endif ()

set (CMAKE_EXE_LINKER_FLAGS
    "-T${LINKER_PATH} \
    -Wl,--gc-sections \
    -Wl,-Map=${PROJECT_NAME}.map")

set (ARCHFLAGS_C
    "-std=gnu11 \
    -Wall \
    -Werror \
    -D_GNU_SOURCE \
    ${COMMON_FLAGS}"
)

set (ARCHFLAGS_CXX
    "-std=gnu11 \
    -Wall \
    -Werror \
    -D_GNU_SOURCE \
    ${COMMON_FLAGS}"
)

set (ARCHFLAGS_DEBUG    "-Og -g -DDEBUG")
set (ARCHFLAGS_RELEASE    "-Os  -flto")