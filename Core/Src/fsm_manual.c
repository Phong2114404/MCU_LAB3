/*
 * fsm_manual.c
 *
 *  Created on: Nov 12, 2023
 *      Author: Phong
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
		case MAN_RED:
			if(timer_flag[2]) {
				scan7SEG(mode, segth++);					//Display modified value and number of MODE
				segth %= 3;
				setTimer(0.5, 2);
			}

			if(timer_flag[0]){
				HAL_GPIO_TogglePin(GPIOB, red1_Pin | red2_Pin);	//Red Leds blink every 0.5 sec
				setTimer(0.5, 0);
			}

			if(isbuttonpressed(0)){								//If BUTTON1 is pressed, change to MODIFY_YELLOW state
				status = MAN_AMBER;
				HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
				break;
			}

			if(isbuttonpressed(2)){								//If BUTTON3 is pressed, RED LEDs' duration = modify_val
				led_duration[RED_DURA] = modify_val;
			}
			break;
		case MAN_AMBER:
			if(timer_flag[2]) {
				scan7SEG(mode, segth++);					//Display modified value and number of MODE
				segth %= 3;
				setTimer(0.5, 2);
			}

			if(timer_flag[0]){
				HAL_GPIO_TogglePin(GPIOB, yellow1_Pin | yellow2_Pin);
				setTimer(0.5, 0);
			}

			if(isbuttonpressed(0)){
				status = MAN_GREEN;
				HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);
				break;
			}

			if(isbuttonpressed(2)){
				led_duration[YELLOW_DURA] = modify_val;
			}
			break;
		case MAN_GREEN:
			if(timer_flag[2]) {
				scan7SEG(mode, segth++);					//Display modified value and number of MODE
				segth %= 3;
				setTimer(0.5, 2);
			}

			if(timer_flag[0]){
				HAL_GPIO_TogglePin(GPIOB, green1_Pin | green2_Pin);
				setTimer(0.5, 0);
			}

			if(isbuttonpressed(0)){
				status = RED_GREEN;
				HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);
				mode = 0;

				if(led_duration[RED_DURA] != led_duration[GREEN_DURA] + led_duration[YELLOW_DURA]){
					led_duration[RED_DURA] = INIT_RED_DURA;			//if red_duration != yellow_duration + green_duration
					led_duration[YELLOW_DURA] = INIT_YELLOW_DURA;	//set all led duration to init_duration
					led_duration[GREEN_DURA] = INIT_GREEN_DURA;		//and change to state INIT
					mode = 1;
				}

				led_count1 = led_duration[RED_DURA];
				led_count2 = led_duration[GREEN_DURA];

				setTimer(led_duration[GREEN_DURA], 1);
				setTimer(1, 0);
				break;
			}

			if(isbuttonpressed(2)){
				led_duration[GREEN_DURA] = modify_val;
			}
			break;
		default:
			break;
	}
	if(isbuttonpressed(1) && mode == 1){
			++modify_val;
			if(modify_val == 100) modify_val = 1;
	}
}

