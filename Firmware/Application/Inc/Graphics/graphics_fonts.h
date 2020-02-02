/**
 ******************************************************************************
 * @file    graphics_fonts.h
 * @author  Daniel Dyringer
 * @date    2020-02-01
 * @brief   <Provide some short description here>
 ******************************************************************************
 */

/* Define to prevent recursive inclusion ----------------------------------- */
#ifndef GRAPHICS_FONTS_H_
#define GRAPHICS_FONTS_H_

/* Includes ---------------------------------------------------------------- */
#include <stdbool.h>
#include <stdint.h>

/** @addtogroup <ID>
 *  @{
 */

/* Constants and macros ---------------------------------------------------- */
// clang-format off


// clang-format on

/* Types ------------------------------------------------------------------- */
typedef enum Font_type_e
{
    Font_type_7x10,
    Font_type_11x18
}Font_type_t;

typedef struct Font_s
{
    uint16_t * fontData;
    uint8_t fontWidth;
    uint8_t fontHeight;
}Font_t;

/* Exposed API ------------------------------------------------------------- */
Font_t font_get(Font_type_t font);

/**
 * @}
 */

#endif /* GRAPHICS_FONTS_H_ */

/**** END OF FILE ****/