#include "oled_shapes.h"
#include "shield_oled.h"
#include <stdlib.h>
#include <string.h>

// Frame buffer for the OLED display
static uint8_t oled_fb[128 * 64 / 8]; // 1024 bytes

// Draw a pixel on the OLED
void OLED_DrawPixel(uint8_t x, uint8_t y, bool on)
{
    if (x >= 128 || y >= 64)
        return;

    uint16_t index = x + (y / 8) * 128;
    uint8_t mask = 1 << (y % 8);

    if (on)
        oled_fb[index] |= mask;
    else
        oled_fb[index] &= ~mask;
}

// Clear the frame buffer
void OLED_ClearFB(void)
{
    memset(oled_fb, 0x00, sizeof(oled_fb));
}

// Update the OLED display with the frame buffer
void OLED_Update(void)
{
    for (uint8_t page = 0; page < 8; page++)
    {
        OLED_SetPage(page);
        OLED_SetSeg(0);
        OLED_Send(&oled_fb[page * 128], 128, OLED_DATA);
    }
}

// Draw a rectangle (row by row)
void DrawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, bool on)
{
    for (uint8_t row = 0; row < h; row++)
    {
        uint8_t y0 = y + row;

        for (uint8_t col = 0; col < w; col++)
        {
            OLED_DrawPixel(x + col, y0, on);
        }
    }
}

// Draw Parabolic curve
void DrawCurve(uint8_t cx, uint8_t cy, uint8_t cw, uint8_t inv)
{
    for (int8_t x = -cw; x <= cw; x++)
    {
        uint8_t y = (x * x) / (cw * 2);
        OLED_DrawPixel(cx + x, cy - y*inv, true);
    }
}



// Draw a triangle using scanline algorithm
void DrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, bool on)
{
    // Sort vertices by Y coordinate
    if (y0 > y1) { int16_t t = y0; y0 = y1; y1 = t; t = x0; x0 = x1; x1 = t; }
    if (y1 > y2) { int16_t t = y1; y1 = y2; y2 = t; t = x1; x1 = x2; x2 = t; }
    if (y0 > y1) { int16_t t = y0; y0 = y1; y1 = t; t = x0; x0 = x1; x1 = t; }

    // Scanline fill
    for (int16_t y = y0; y <= y2; y++)
    {
        int16_t xa, xb;

        if (y < y1)
        {
            // Upper half
            xa = x0 + (x1 - x0) * (y - y0) / (y1 - y0);
            xb = x0 + (x2 - x0) * (y - y0) / (y2 - y0);
        }
        else
        {
            // Lower half
            xa = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
            xb = x0 + (x2 - x0) * (y - y0) / (y2 - y0);
        }

        if (xa > xb) { int16_t t = xa; xa = xb; xb = t; }

        for (int16_t x = xa; x <= xb; x++)
        {
            OLED_DrawPixel(x, y, on);
        }
    }
}

void DrawEyelid(Shape eyelid, uint8_t x, uint8_t y, uint8_t xtu, uint8_t xtb, uint8_t ytu, uint8_t ytb, uint8_t w, uint8_t h, uint8_t blink)
{
	if (eyelid == RECTANGLE)
	{
		DrawRect(x, y, w, blink, false);
        DrawRect(x, y+h-blink, w, blink, false);
	}
	else if (eyelid == TRIANGLE)
	{
		DrawTriangle(x, y, x + w, y, xtu, ytu + blink, false);
		DrawTriangle(x, y + h, x + w, y + h, xtb, ytb - blink, false);
	}
}

void DrawMouth(Shape mouth, uint8_t cx, uint8_t cy, uint8_t cw, uint8_t inv, uint8_t blink)
{
	if (mouth == RECTANGLE)
	{
		DrawRect(cx, cy, cw, 0.25*cw + blink, true);
	}
	else if (mouth == CURVE)
	{
		DrawCurve(cx, cy, cw, inv);
	}
}


//Draw face function
void DrawFace(Shape eyelid, uint8_t xrl, uint8_t xrr, uint8_t yr, uint8_t xtlu, uint8_t xtlb, uint8_t xtru, uint8_t xtrb, uint8_t ytu, uint8_t ytb, uint8_t w, uint8_t h, Shape mouth, uint8_t cx, uint8_t cy, uint8_t cw, uint8_t inv, uint8_t blink)
{
    OLED_ClearFB();

    DrawRect(xrl, yr, w, h, true);
    DrawEyelid(eyelid, xrl, yr, xtlu, xtlb, ytu, ytb, w, h, blink);



    DrawRect(xrr, yr, w, h, true);
    DrawEyelid(eyelid, xrr, yr, xtru, xtrb, ytu, ytb, w, h, blink);

    DrawMouth(mouth, cx, cy, cw, inv, blink);

    OLED_Update();
}




