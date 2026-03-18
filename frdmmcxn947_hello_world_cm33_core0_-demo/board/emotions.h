#ifndef EMOTIONS_H
#define EMOTIONS_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    IDLE,
    HAPPY,
    SAD,
	ANGRY,
	SLEEPY
} Emotion;

void DrawEmotion(Emotion emotion);

#endif
