/*
 * fsm_automatic.c
 *
 *  Created on: Nov 12, 2023
 *      Author: Phong
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, GPIO_PIN_SET);

		status = RED_GREEN;
		setTimer(1, 0);
		setTimer(led_duration[GREEN_DURA], 1);
		setTimer(0.5, 2);
		break;

	case RED_GREEN:
		if(timer_flag[1] == 1){
			led_count2 = led_duration[YELLOW_DURA];
			++led_count1;
			++led_count2;
			status = RED_AMBER;

			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);

			setTimer(led_duration[YELLOW_DURA], 1);
		}
		else{
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_RESET);
			if(timer_flag[2]){
				scan7SEG(mode, segth++);
				segth %= 4;
				setTimer(0.5, 2);

			}
		}
		if(isbuttonpressed(0)){
			status = MAN_RED;
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);
			mode = 1;
			setTimer(0.5, 0);
		}
		break;

	case RED_AMBER:

		if(timer_flag[1] == 1){
			led_count1 = led_duration[GREEN_DURA];
			led_count2 = led_duration[RED_DURA];
			++led_count1;
			++led_count2;
			status = GREEN_RED;
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);
			setTimer(led_duration[GREEN_DURA], 1);
		}
		else{
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_RESET);

			if(timer_flag[2]) {
				scan7SEG(mode, segth++);
				segth %= 4;
				setTimer(0.5, 2);
			}
		}
		if(isbuttonpressed(0)){
			status = MAN_RED;
			HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);
			mode = 1;
			setTimer(0.5, 0);
		}
		break;

	case GREEN_RED:
		if(timer_flag[1]){
			led_count1 = led_duration[YELLOW_DURA];
			++led_count1;
			++led_count2;
			status = AMBER_RED;
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
			setTimer(led_duration[YELLOW_DURA], 1);
		}
		else{
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_RESET);
			if(timer_flag[2]) {
				scan7SEG(mode, segth++);
				segth %= 4;
				setTimer(5, 2);
			}
		}

		if(isbuttonpressed(0)){
			status = MAN_RED;
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
			mode = 1;
			setTimer(0.5, 0);
		}
		break;

	case AMBER_RED:
		if(timer_flag[1]){
			led_count1 = led_duration[RED_DURA];
			led_count2 = led_duration[GREEN_DURA];
			++led_count1;
			++led_count2;
			status = RED_GREEN;
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
			setTimer(led_duration[GREEN_DURA], 1);
			}
		else{
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_RESET);

			if(timer_flag[2]) {
			scan7SEG(mode, segth++);
			segth %= 4;
			setTimer(0.5, 2);
			}
		}

		if(isbuttonpressed(0)){
			status = MAN_RED;
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
			mode = 1;
			setTimer(0.5, 0);
			}
		break;

	default:
		break;
	}
	if(timer_flag[0] && mode == 0){
		if(led_count1 > 0) --led_count1;
		if(led_count2 > 0) --led_count2;
		setTimer(1, 0);
	}
}
