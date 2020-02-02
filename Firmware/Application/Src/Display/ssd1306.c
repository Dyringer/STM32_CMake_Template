/**
 ******************************************************************************
 * @file    ssd1306.c
 * @author  Daniel Dyringer
 * @date    2020-02-01
 * @brief   <Provide some short description here>
 ******************************************************************************
*/


/* Includes ---------------------------------------------------------------- */
#include "Display/ssd1306.h"
#include "Display/ssd1306_io.h"
#include <string.h>

/** @addtogroup <ID>
*  @{
*/

/* Constants and macros ---------------------------------------------------- */
// clang-format off

#define SSD1306_SCRREN_WIDTH                        128u
#define SSD1306_SCRREN_HEIGHT_64                    64u
#define SSD1306_SCRREN_HEIGHT_32                    32u

// clang-format on

/* Private types ----------------------------------------------------------- */


/* Private variables ------------------------------------------------------- */
static struct
{
    uint8_t * screenBuffer;
    Graphics_position_t currentPosition;
    SSD1306_size_t size;
    bool inverted;
    bool initialized;
} ssd1306_data;

/* Private functions ------------------------------------------------------- */
static bool ssd1306_pixelOnScreen(Graphics_position_t position)
{
    const uint8_t height = (ssd1306_data.size == SSD1306_size_128x32) ?
        SSD1306_SCRREN_HEIGHT_32 : SSD1306_SCRREN_HEIGHT_64;
    const bool ret = ((position.x < SSD1306_SCRREN_WIDTH) && (position.y < height));
    return ret;
}

/* Exposed API ------------------------------------------------------------- */
int ssd1306_init(SSD1306_size_t size, uint8_t * const scrrenBuffer)
{
    int ret = 0;
    do
    {
        ssd1306_writeCommand(0xAE); //display off
        ssd1306_writeCommand(0x20); //Set Memory Addressing Mode
        ssd1306_writeCommand(0x10); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
        ssd1306_writeCommand(0xB0); //Set Page Start Address for Page Addressing Mode,0-7
        ssd1306_writeCommand(0xC8); //Set COM Output Scan Direction
        ssd1306_writeCommand(0x00); //---set low column address
        ssd1306_writeCommand(0x10); //---set high column address
        ssd1306_writeCommand(0x40); //--set start line address
        ssd1306_writeCommand(0x81); //--set contrast control register
        ssd1306_writeCommand(0xFF);
        ssd1306_writeCommand(0xA1); //--set segment re-map 0 to 127
        ssd1306_writeCommand(0xA6); //--set normal display
        ssd1306_writeCommand(0xA8); //--set multiplex ratio(1 to 64)
        ssd1306_writeCommand(0x3F); //
        ssd1306_writeCommand(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
        ssd1306_writeCommand(0xD3); //-set display offset
        ssd1306_writeCommand(0x00); //-not offset
        ssd1306_writeCommand(0xD5); //--set display clock divide ratio/oscillator frequency
        ssd1306_writeCommand(0xF0); //--set divide ratio
        ssd1306_writeCommand(0xD9); //--set pre-charge period
        ssd1306_writeCommand(0x22); //
        ssd1306_writeCommand(0xDA); //--set com pins hardware configuration
        ssd1306_writeCommand(0x12);
        ssd1306_writeCommand(0xDB); //--set vcomh
        ssd1306_writeCommand(0x40); //0x40,0.77xVcc
        ssd1306_writeCommand(0x8D); //--set DC-DC enable
        ssd1306_writeCommand(0x14); //
        ssd1306_writeCommand(0xAF); //--turn on SSD1306 panel

        ssd1306_data.size = size;
        ssd1306_data.initialized = true;
        ssd1306_data.currentPosition.x = 0;
        ssd1306_data.currentPosition.y = 0;
        ssd1306_data.screenBuffer = scrrenBuffer;
        ssd1306_fill(Graphics_color_black);
        ssd1306_updateScreen();

    } while (0);

    return ret;
}

void ssd1306_setPixel(Graphics_position_t position, Graphics_color_t color)
{
    if (ssd1306_pixelOnScreen(position))
    {
        const uint16_t byte = position.x + ((position.y / 8) * SSD1306_SCRREN_WIDTH);
        if (color == Graphics_color_white)
        {
            ssd1306_data.screenBuffer[byte] |= 1 << (position.y % 8);
        }
        else
        {
            ssd1306_data.screenBuffer[byte] &= ~(1 << (position.y % 8));
        }
    }
}

Graphics_color_t ssd1306_getPixel(Graphics_position_t position)
{
    Graphics_color_t ret = Graphics_color_black;
    if (ssd1306_pixelOnScreen(position))
    {
        const uint16_t byte = position.x + ((position.y / 8) * SSD1306_SCRREN_WIDTH);
        const uint8_t pixel = ssd1306_data.screenBuffer[byte] & (1 << (position.y % 8));
        if (pixel)
        {
            ret = Graphics_color_white;
        }
    }

    return ret;
}

int ssd1306_updateScreen(void)
{
    int ret = -1;
    if (ssd1306_data.initialized)
    {

    	for (uint8_t y = 0; y < 8; ++y)
    	{
    		ssd1306_writeCommand(0xB0 + y);
    		ssd1306_writeCommand(0x00);
    		ssd1306_writeCommand(0x10);
    		ssd1306_writeBuffer(&(ssd1306_data.screenBuffer[(SSD1306_SCRREN_WIDTH * y)]), SSD1306_SCRREN_WIDTH);
    	}
        ret = 0;
    }

    return ret;
}

void ssd1306_invert(bool inverted)
{
    ssd1306_data.inverted = inverted;
}

void ssd1306_fill(Graphics_color_t color)
{
    if (ssd1306_data.initialized)
    {
        const uint16_t size = (ssd1306_data.size == SSD1306_size_128x32) ?
            SSD1306_SCREENBUFFER_SIZE_128_32 :
            SSD1306_SCREENBUFFER_SIZE_128_64;

        memset(ssd1306_data.screenBuffer, (int)color, size);
    }
}

/**
* @}
*/

/**** END OF FILE ****/
