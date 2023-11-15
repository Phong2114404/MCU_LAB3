/*
 * software_timer.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Phong
 */
#include "software_timer.h"

int timer_counter[3] = {0, 0, 0};
// index 1: for second
// index 2: for led duration
// index 3: for scan 7SEG
int timer_flag[3] = {0, 0, 0};

void setTimer(float duration, int id){
	timer_counter[id] = (int) (1000 * duration) / TIMER_DURATION;
	timer_flag[id] = 0;
}

void timerRun(int id){
	if(timer_counter[id] > 0){
		timer_counter[id]--;
		if(timer_counter[id] <= 0){
			timer_flag[id] = 1;
		}
	}
}
