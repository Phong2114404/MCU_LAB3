/*
 * button.c
 *
 *  Created on: Nov 12, 2023
 *      Author: Phong
 */

#include "button.h"

int button_flag[3] = {0, 0, 0};

int keyreg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyreg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyreg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int keyreg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int timerforkeypress = 50;

void subkeyprocess(int id) {
	button_flag[id] = 1;
}

int isbuttonpressed(int id){
	if(button_flag[id] == 1){
		button_flag[id] = 0;
		return 1;
	}
	return 0;
}

void getkeyinput(int id, uint16_t button){
	keyreg0[id] = keyreg1[id];
	keyreg1[id] = keyreg2[id];
	keyreg2[id] = HAL_GPIO_ReadPin(GPIOA, button);

	if(keyreg0[id] == keyreg1[id] && keyreg1[id] == keyreg2[id]){
		if(keyreg2[id] != keyreg3[id]){
			keyreg3[id] = keyreg2[id];

			if(keyreg2[id] == PRESSED_STATE){
				subkeyprocess(id);
				timerforkeypress = 50;
			}
		}
		else{
			timerforkeypress--;
			if(timerforkeypress <= 0){
				if(keyreg2[id] == PRESSED_STATE){
					subkeyprocess(id);
				}

				timerforkeypress = 50;
			}
		}
	}
}
