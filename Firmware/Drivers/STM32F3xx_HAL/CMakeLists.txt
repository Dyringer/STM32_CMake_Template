## Project ----------------------------------------------------------------------------- #
cmake_minimum_required (VERSION 3.10)
project (STM32_Device)

## Variables --------------------------------------------------------------------------- #
set (LIBRARY_NAME "STM32_HAL")

## Configuration -------------------- -------------------------------------------------- #

## Include submodules ------------------------------------------------------------------ #

## Includes ---------------------------------------------------------------------------- #
set (INCLUDES_HAL
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Legacy/inc
    ${INCLUDES_STM32}
)
message( ${INCLUDES_HAL} )
## Sources ----------------------------------------------------------------------------- #
set (SOURCES
    Src/Legacy/stm32f3xx_hal_can
    Src/stm32f3xx_hal.c
    Src/stm32f3xx_hal_adc.c
    Src/stm32f3xx_hal_adc_ex.c
    Src/stm32f3xx_hal_can.c
    Src/stm32f3xx_hal_cec.c
    Src/stm32f3xx_hal_comp.c
    Src/stm32f3xx_hal_cortex.c
    Src/stm32f3xx_hal_crc.c
    Src/stm32f3xx_hal_crc_ex.c
    Src/stm32f3xx_hal_dac.c
    Src/stm32f3xx_hal_dac_ex.c
    Src/stm32f3xx_hal_dma.c
    Src/stm32f3xx_hal_exti.c
    Src/stm32f3xx_hal_flash.c
    Src/stm32f3xx_hal_flash_ex.c
    Src/stm32f3xx_hal_gpio.c
    Src/stm32f3xx_hal_hrtim.c
    Src/stm32f3xx_hal_i2c.c
    Src/stm32f3xx_hal_i2c_ex.c
    Src/stm32f3xx_hal_i2s.c
    Src/stm32f3xx_hal_i2s_ex.c
    Src/stm32f3xx_hal_irda.c
    Src/stm32f3xx_hal_iwdg.c
    Src/stm32f3xx_hal_nand.c
    Src/stm32f3xx_hal_nor.c
    Src/stm32f3xx_hal_opamp.c
    Src/stm32f3xx_hal_opamp_ex.c
    Src/stm32f3xx_hal_pccard.c
    Src/stm32f3xx_hal_pcd.c
    Src/stm32f3xx_hal_pcd_ex.c
    Src/stm32f3xx_hal_pwr.c
    Src/stm32f3xx_hal_pwr_ex.c
    Src/stm32f3xx_hal_rcc.c
    Src/stm32f3xx_hal_rcc_ex.c
    Src/stm32f3xx_hal_rtc.c
    Src/stm32f3xx_hal_rtc_ex.c
    Src/stm32f3xx_hal_sdadc.c
    Src/stm32f3xx_hal_smartcard.c
    Src/stm32f3xx_hal_smartcard_ex.c
    Src/stm32f3xx_hal_smbus.c
    Src/stm32f3xx_hal_spi.c
    Src/stm32f3xx_hal_spi_ex.c
    Src/stm32f3xx_hal_sram.c
    Src/stm32f3xx_hal_tim.c
    Src/stm32f3xx_hal_tim_ex.c
    Src/stm32f3xx_hal_tsc.c
    Src/stm32f3xx_hal_uart.c
    Src/stm32f3xx_hal_uart_ex.c
    Src/stm32f3xx_hal_usart.c
    Src/stm32f3xx_hal_usart_ex.c
    Src/stm32f3xx_hal_wwdg.c
    Src/stm32f3xx_ll_adc.c
    Src/stm32f3xx_ll_comp.c
    Src/stm32f3xx_ll_crc.c
    Src/stm32f3xx_ll_dac.c
    Src/stm32f3xx_ll_dma.c
    Src/stm32f3xx_ll_exti.c
    Src/stm32f3xx_ll_fmc.c
    Src/stm32f3xx_ll_gpio.c
    Src/stm32f3xx_ll_hrtim.c
    Src/stm32f3xx_ll_i2c.c
    Src/stm32f3xx_ll_opamp.c
    Src/stm32f3xx_ll_pwr.c
    Src/stm32f3xx_ll_rcc.c
    Src/stm32f3xx_ll_rtc.c
    Src/stm32f3xx_ll_spi.c
    Src/stm32f3xx_ll_tim.c
    Src/stm32f3xx_ll_usart.c
    Src/stm32f3xx_ll_usb.c
    Src/stm32f3xx_ll_utils.c
)

## Jobs -------------------------------------------------------------------------------- #
add_library (${LIBRARY_NAME} STATIC ${SOURCES})
add_dependencies(${LIBRARY_NAME} STM32_CMSIS)
target_link_libraries(${LIBRARY_NAME} STM32_CMSIS)
target_include_directories (${LIBRARY_NAME} PUBLIC ${INCLUDES_HAL})