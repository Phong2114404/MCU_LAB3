/*
 * software_timer.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Phong
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIMER_DURATION 10

extern int timer_counter[3];
extern int timer_flag[3];

void setTimer(float duration, int id);
void timerRun(int id);

#endif /* INC_SOFTWARE_TIMER_H_ */
