#ifndef OLED_SHAPES_H
#define OLED_SHAPES_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    TRIANGLE,
    RECTANGLE,
	CURVE,
    NONE
} Shape;
void DrawFace
(
    Shape eyelid, //Toggle between triangle and rectangle eyelids
    uint8_t xrl, //x coordinate of left eye
    uint8_t xrr, //x coordinate of right eye
    uint8_t yr, //y coordinate of both eyes
    uint8_t xtlu, //x coordinate of left triangle upper eyelid
    uint8_t xtlb, //x coordinate of left triangle lower eyelid
    uint8_t xtru, //x coordinate of right triangle upper eyelid
    uint8_t xtrb, //x coordinate of right triangle lower eyelid
    uint8_t ytu, //y coordinate of both upper eyelids
    uint8_t ytb, //y coordinate of both lower eyelids
    uint8_t w, //eye width
    uint8_t h, //eye height
	Shape mouth,
    uint8_t cx, //x coordinate of centre of curve
    uint8_t cy, //y coordinate of centre of curve
    uint8_t cw, //width of curve
    uint8_t inv, //inverse of curve
    uint8_t blink //blink animation
);


#endif // OLED_SHAPES_H
