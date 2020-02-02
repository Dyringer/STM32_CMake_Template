/**
 ******************************************************************************
 * @file    ssd1306_io.h
 * @author  Daniel Dyringer
 * @date    2020-02-01
 * @brief   <Provide some short description here>
 ******************************************************************************
 */

/* Define to prevent recursive inclusion ----------------------------------- */
#ifndef SSD1306_IO_H_
#define SSD1306_IO_H_

/* Includes ---------------------------------------------------------------- */
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
/** @addtogroup <ID>
 *  @{
 */

/* Constants and macros ---------------------------------------------------- */
// clang-format off


// clang-format on

/* Types ------------------------------------------------------------------- */


/* Exposed API ------------------------------------------------------------- */
int ssd1306_writeCommand(uint8_t command);
int ssd1306_writeBuffer(uint8_t * const buffer, size_t size);

/**
 * @}
 */

#endif /* SSD1306_IO_H_ */

/**** END OF FILE ****/
