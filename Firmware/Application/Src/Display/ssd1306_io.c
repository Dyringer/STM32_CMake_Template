/**
 ******************************************************************************
 * @file    ssd1306_io.c
 * @author  Daniel Dyringer
 * @date    2020-02-01
 * @brief   <Provide some short description here>
 ******************************************************************************
*/


/* Includes ---------------------------------------------------------------- */
#include "Display/ssd1306_io.h"
#include "stm32f3xx_hal.h"

/** @addtogroup <ID>
*  @{
*/

/* Constants and macros ---------------------------------------------------- */
// clang-format off
#define SSD1306_I2C_ADDR                            0x78

// clang-format on

/* Private types ----------------------------------------------------------- */
extern I2C_HandleTypeDef hi2c1;

/* Private variables ------------------------------------------------------- */


/* Private functions ------------------------------------------------------- */


/* Exposed API ------------------------------------------------------------- */
int ssd1306_writeCommand(uint8_t command)
{
	HAL_I2C_Mem_Write(&hi2c1, SSD1306_I2C_ADDR, 0x00, 1, &command, 1, 10);
	return 0;
}

int ssd1306_writeBuffer(uint8_t * const buffer, size_t size)
{
	HAL_I2C_Mem_Write(&hi2c1, SSD1306_I2C_ADDR, 0x40, 1, buffer, size, 10);
	return 0;
}

/**
* @}
*/

/**** END OF FILE ****/
