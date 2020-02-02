/**
 ******************************************************************************
 * @file    graphics_types.h
 * @author  Daniel Dyringer
 * @date    2020-02-01
 * @brief   <Provide some short description here>
 ******************************************************************************
 */

/* Define to prevent recursive inclusion ----------------------------------- */
#ifndef GRAPHICS_TYPES_H_
#define GRAPHICS_TYPES_H_

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
typedef enum Graphics_color_s
{
    Graphics_color_black = 0,
    Graphics_color_white = 1
} Graphics_color_t;

typedef struct Graphics_position_s
{
    uint8_t x;
    uint8_t y;
} Graphics_position_t;

/* Exposed API ------------------------------------------------------------- */


/**
 * @}
 */

#endif /* GRAPHICS_TYPES_H_ */

/**** END OF FILE ****/