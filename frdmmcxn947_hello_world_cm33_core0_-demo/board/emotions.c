#include "emotions.h"
#include "oled_shapes.h"
#include "animations.h"
#include <stdlib.h>


void DrawEmotion(Emotion emotion)
{
	static uint8_t blink = 0;
	blink = openClose(blink);
	
    switch(emotion)
    {
        case IDLE:
        	DrawFace(RECTANGLE, 31, 79, 11, 0, 0, 0, 0, 0, 0, 20, 20, CURVE, 64, 60, 25 + 0.5*blink, 1, blink);
            break;
            
        case HAPPY:
        	 DrawFace(TRIANGLE, 31, 79, 11, 31, 51, 99, 79, 15, 31, 20, 20, CURVE, 64, 60, 25 + blink, 1, blink);
            break;
            
        case SAD:
        	DrawFace(TRIANGLE, 31, 79, 11, 31, 51, 99, 79, 15, 31, 20, 20, CURVE, 64, 45, 25 + 0.5*blink, -1, blink);
            break;
            
        case ANGRY:
        	DrawFace(TRIANGLE, 31, 79, 11, 51, 51, 79, 79, 15, 38, 20, 20, CURVE, 64, 45, 25 + blink, -1, blink);
            break;

        case SLEEPY:
			DrawFace(NONE, 31, 79, 28, 0, 0, 0, 0, 0, 0, 20, 3, RECTANGLE, 49, 45, 30, 1, blink);
			break;

    }
}
