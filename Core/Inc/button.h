/*
 * button.h
 *
 *  Created on: Nov 12, 2023
 *      Author: Phong
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button_flag[3];

void subkeyprocess(int id);

int isbuttonpressed(int id);

void getkeyinput(int id, uint16_t button);

#endif /* INC_BUTTON_H_ */
