/**
 ******************************************************************************
 * @file    ssd1306.h
 * @author  Daniel Dyringer
 * @date    2020-02-01
 * @brief   <Provide some short description here>
 ******************************************************************************
 */

/* Define to prevent recursive inclusion ----------------------------------- */
#ifndef SSD1306_H_
#define SSD1306_H_

/* Includes ---------------------------------------------------------------- */
#include <stdbool.h>
#include <stdint.h>
#include "Graphics/graphics_types.h"

/** @addtogroup <ID>
 *  @{
 */

/* Constants and macros ---------------------------------------------------- */
// clang-format off
#define SSD1306_SCREENBUFFER_SIZE_128_64            (128u * 64u / 8u)
#define SSD1306_SCREENBUFFER_SIZE_128_32            (128u * 32u / 8u)

// clang-format on

/* Types ------------------------------------------------------------------- */
typedef enum SSD1306_size_s
{
    SSD1306_size_128x64,
    SSD1306_size_128x32
} SSD1306_size_t;

/* Exposed API ------------------------------------------------------------- */
int ssd1306_init(SSD1306_size_t size, uint8_t * const scrrenBuffer);
uint8_t ssd1306_sizeToHeight(SSD1306_size_t size);

void ssd1306_setPixel(Graphics_position_t position, Graphics_color_t color);
Graphics_color_t ssd1306_getPixel(Graphics_position_t position);

int ssd1306_updateScreen(void);
void ssd1306_invert(bool inverted);
void ssd1306_fill(Graphics_color_t color);

/**
 * @}
 */

#endif /* SSD1306_H_ */

/**** END OF FILE ****/