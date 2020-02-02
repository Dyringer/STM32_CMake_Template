/**
 ******************************************************************************
 * @file    graphics.c
 * @author  Daniel Dyringer
 * @date    2020-02-01
 * @brief   <Provide some short description here>
 ******************************************************************************
*/

/* Includes ---------------------------------------------------------------- */
#include "Graphics/graphics.h"
#include <stddef.h>
#include <string.h>
#include  <stdlib.h>

/** @addtogroup <ID>
*  @{
*/

/* Constants and macros ---------------------------------------------------- */
// clang-format off
#define GRAPHICS_SWAP_I16(a, b) { int16_t t = a; a = b; b = t; }
#define GRAPHICS_SWAP_U8(a, b) { uint8_t t = a; a = b; b = t; }

// clang-format on

/* Private types ----------------------------------------------------------- */

/* Private variables ------------------------------------------------------- */
static struct
{
    Graphics_setPixel_t pixelSetter;
    Graphics_getPixel_t pixelGetter;
    uint8_t screenWidth;
    uint8_t screenHeight;
    Graphics_position_t currentPosition;
    bool initialized;
} graphics_data;

/* Private functions ------------------------------------------------------- */

/* Exposed API ------------------------------------------------------------- */
void graphics_init(
    Graphics_setPixel_t pixelSetter,
    Graphics_getPixel_t pixelGetter,
    uint8_t screenWidth,
    uint8_t screenHeight)
{
    if ((pixelSetter) && (pixelGetter))
    {
        graphics_data.pixelSetter = pixelSetter;
        graphics_data.pixelGetter = pixelGetter;
        graphics_data.screenHeight = screenHeight;
        graphics_data.screenWidth = screenWidth;
        graphics_data.initialized = true;
    }
}

void graphics_setPosition(Graphics_position_t position)
{
    graphics_data.currentPosition = position;
}

Graphics_position_t graphics_getPosition(void)
{
    return graphics_data.currentPosition;
}

void graphics_drawChar(char c, Graphics_color_t color, Font_type_t font)
{
    if (graphics_data.initialized)
    {
        const Font_t fontData = font_get(font);
        for (uint8_t i = 0; i < fontData.fontHeight; ++i)
        {
            uint16_t b = fontData.fontData[(c - 32) * fontData.fontHeight + i];
            Graphics_position_t pixelPos;
            pixelPos.y = graphics_data.currentPosition.y + i;
            for (uint8_t j = 0; j < fontData.fontWidth; ++j)
            {
                const Graphics_color_t pixelColor = ((b << j) & 0x8000) ? color : !color;
                pixelPos.x = graphics_data.currentPosition.x + j;
                graphics_data.pixelSetter(pixelPos, pixelColor);
            }
        }

        graphics_data.currentPosition.x += fontData.fontWidth;
    }
}

void graphics_drawString(
    const char *const str,
    Graphics_color_t color,
    Font_type_t font,
    Graphics_alignment_t alignment)
{
    if ((str != NULL) && (graphics_data.initialized))
    {
        char *charPtr = (char *)str;
        const Font_t fontData = font_get(font);
        if (alignment != Graphics_alignment_none)
        {
            Graphics_position_t newPosition = graphics_getPosition();
            const uint8_t stringWidth = strlen(charPtr) * fontData.fontWidth;
            switch (alignment)
            {
            case Graphics_alignment_left:
            {
            	newPosition.x = 0;
                graphics_setPosition(newPosition);
            }
            break;
            case Graphics_alignment_right:
            {
                newPosition.x = graphics_data.screenWidth - stringWidth;
                graphics_setPosition(newPosition);
            }
            break;
            case Graphics_alignment_centeredScrren:
            {
                newPosition.x = (graphics_data.screenWidth / 2) - (stringWidth / 2);
                graphics_setPosition(newPosition);
            }
            break;
            case Graphics_alignment_centeredPos:
            {
                newPosition.x = graphics_data.currentPosition.x - (stringWidth / 2);
                graphics_setPosition(newPosition);
            }
            break;
            default:
                break;
            }
        }

        while (*charPtr)
        {
            graphics_drawChar(*charPtr, color, font);
            ++charPtr;
        }
    }
}

void graphics_drawLine(Graphics_position_t a, Graphics_position_t b, Graphics_color_t color)
{
    int8_t steep = abs(b.y - a.y) > abs(b.x - a.x);
    if (steep)
    {
        GRAPHICS_SWAP_I16(a.x, a.y);
        GRAPHICS_SWAP_I16(b.x, b.y);
    }

    if (a.x > b.x)
    {
        GRAPHICS_SWAP_I16(a.x, b.x);
        GRAPHICS_SWAP_I16(a.y, b.y);
    }

    int8_t dx = b.x - a.x;
    int8_t dy = abs(b.y - a.y);
    int8_t err = dx / 2;
    int8_t ystep = (a.y < b.y) ? 1 : -1;

    for (; a.x <= b.x; a.x++)
    {
        Graphics_position_t pixelPos = { 0 };
        if (steep)
        {
            pixelPos.x = a.y;
            pixelPos.y = a.x;
        }
        else
        {
            pixelPos.x = a.x;
            pixelPos.y = a.y;
        }

        graphics_data.pixelSetter(pixelPos, color);
        err -= dy;
        if (err < 0)
        {
            a.y += ystep;
            err += dx;
        }
    }
}

/**
* @}
*/

/**** END OF FILE ****/
