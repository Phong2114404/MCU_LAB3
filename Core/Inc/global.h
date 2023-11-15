/*
 * global.h
 *
 *  Created on: Nov 12, 2023
 *      Author: Phong
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT 		0
#define RED_GREEN	1
#define RED_AMBER	2
#define GREEN_RED	3
#define AMBER_RED	4

#define MAN_RED		12
#define MAN_AMBER	13
#define MAN_GREEN	14

#define RED_DURA	0
#define YELLOW_DURA	1
#define GREEN_DURA	2

#define INIT_RED_DURA		5
#define INIT_YELLOW_DURA	2
#define INIT_GREEN_DURA		3

extern uint16_t status;
extern uint16_t modify_val;
extern uint8_t led_count1;
extern uint8_t led_count2;

extern uint8_t mode;
extern uint8_t segth;

extern uint8_t led_duration[3];


void display7SEG(int num);
void scan7SEG(int mode, int index);

#endif /* INC_GLOBAL_H_ */
