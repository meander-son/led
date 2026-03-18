/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"
#include <stdint.h>

#include "shield_oled.h"
#include "oled_shapes.h"
#include "emotions.h"
#include "animations.h"
#include "pin_mux.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    /* Init board hardware. */
    BOARD_InitHardware();

    /* attach FRO 12M to FLEXCOMM7 */
	CLOCK_SetClkDiv(kCLOCK_DivFlexcom7Clk, 1u);
	CLOCK_AttachClk(kFRO12M_to_FLEXCOMM7);

	SDK_DelayAtLeastUs(1000000, CLOCK_GetFreq(kCLOCK_CoreSysClk));

	OLED_Init();


uint8_t reading = 0;
static uint8_t prevReading = 0;
uint32_t counter = 0;
uint32_t maxCounter = 50; //5 seconds


	while (1)
	{

		///////////////////////////////////////////
		// BUTTON INPUT TO SIMULATE LDR READINGS //
		///////////////////////////////////////////
//		if (GPIO_PinRead(BOARD_INITPINS_SW_1_GPIO, BOARD_INITPINS_SW_1_PIN)==0)
//		{
//			reading = 1;
//		}
//		else if (GPIO_PinRead(BOARD_INITPINS_SW_2_GPIO, BOARD_INITPINS_SW_2_PIN)==0)
//		{
//			reading = 2;
//		}
		static uint32_t t = 0;
		if (++t >= 100) { reading = (reading + 1) % 5; t = 0; }


//prototype button induced animations
//		counter ++;
//		if (reading == 2 && counter >= maxCounter)
//		{
//			reading = 3;
//			counter = 0;
//		}
//		if (reading == 1 && counter >= maxCounter)
//		{
//			reading = 0;
//			counter = 0;
//		}
//		if (reading == 0 && counter >= maxCounter && checkEyesClosed())
//		{
//			reading = 4;
//			counter = 0;
//		}
//		if (reading != prevReading)
//		{
//			counter = 0;
//		}
//		prevReading = reading;

		if (reading == 1)
			DrawEmotion(HAPPY);
		else if (reading == 2)
			DrawEmotion(SAD);
		else if (reading == 3)
			DrawEmotion(ANGRY);
		else if (reading == 4)
			DrawEmotion(SLEEPY);
		else if (reading == 0)
			DrawEmotion(IDLE);
	}
}
