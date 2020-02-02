/**
 ******************************************************************************
 * @file    graphics.h
 * @author  Daniel Dyringer
 * @date    2020-02-01
 * @brief   <Provide some short description here>
 ******************************************************************************
 */

/* Define to prevent recursive inclusion ----------------------------------- */
#ifndef GRAPHICS_H_
#define GRAPHICS_H_

/* Includes ---------------------------------------------------------------- */
#include <stdbool.h>
#include <stdint.h>
#include "Graphics/graphics_types.h"
#include "Graphics/graphics_fonts.h"

/** @addtogroup <ID>
 *  @{
 */

/* Constants and macros ---------------------------------------------------- */
// clang-format off


// clang-format on

/* Types ------------------------------------------------------------------- */
typedef void (*Graphics_setPixel_t)(Graphics_position_t, Graphics_color_t);
typedef Graphics_color_t (*Graphics_getPixel_t)(Graphics_position_t);
typedef enum Graphics_alignment_e
{
    Graphics_alignment_none,
    Graphics_alignment_left,
    Graphics_alignment_right,
    Graphics_alignment_centeredScrren,
    Graphics_alignment_centeredPos
}Graphics_alignment_t;

/* Exposed API ------------------------------------------------------------- */
void graphics_init(
    Graphics_setPixel_t pixelSetter,
    Graphics_getPixel_t pixelGetter,
    uint8_t screenWidth,
    uint8_t screenHeight);

void graphics_setPosition(Graphics_position_t position);
Graphics_position_t graphics_getPosition(void);

void graphics_drawChar(char c, Graphics_color_t color, Font_type_t font);
void graphics_drawString(
    const char* const str,
    Graphics_color_t color,
    Font_type_t font,
    Graphics_alignment_t alignment);

void graphics_drawLine(Graphics_position_t a, Graphics_position_t b, Graphics_color_t color);

/**
 * @}
 */

#endif /* GRAPHICS_H_ */

/**** END OF FILE ****/