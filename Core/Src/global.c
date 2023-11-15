/*
 * global.c
 *
 *  Created on: Nov 12, 2023
 *      Author: Phong
 */

#include "global.h"

uint16_t modify_val = 1;
uint16_t status = INIT;
uint8_t led_duration[3] = {INIT_RED_DURA, INIT_YELLOW_DURA, INIT_GREEN_DURA};

uint8_t led_count1 = INIT_RED_DURA;
uint8_t led_count2 = INIT_GREEN_DURA;

uint8_t mode = 0;
uint8_t segth = 0;

void display7SEG(int num)
{
    const int segments[10] = {
        0b00111111, // 0
        0b00000110, // 1
        0b01011011, // 2
        0b01001111, // 3
        0b01100110, // 4
        0b01101101, // 5
        0b01111101, // 6
        0b00000111, // 7
        0b01111111, // 8
        0b01101111  // 9
    };

    uint8_t displaySegments = segments[num];

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, (displaySegments & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, ((displaySegments >> 1) & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, ((displaySegments >> 2) & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, ((displaySegments >> 3) & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, ((displaySegments >> 4) & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, ((displaySegments >> 5) & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, ((displaySegments >> 6) & 0x01) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void scan7SEG(int mode, int index){
	if(mode == 0){
				switch(index){
						case 0:
							HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, 0);
							HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 1);
							HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 1);
							HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 1);
							display7SEG(led_count1 / 10);
							break;
						case 1:
							HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, 1);
							HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
							HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 1);
							HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 1);
							display7SEG(led_count1 % 10);
							break;
						case 2:
							HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, 1);
							HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 1);
							HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
							HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 1);
							display7SEG(led_count2 / 10);
							break;
						case 3:
							HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, 1);
							HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 1);
							HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 1);
							HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 3);
							display7SEG(led_count2 % 10);
							break;
						default:
							HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, 0);
							HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
							HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
							HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
							break;
				}

			}
		else{
				switch(index){
						case 0:
							HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, 0);
							HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 1);
							HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 1);
							HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 1);
							display7SEG(modify_val / 10);
							break;
						case 1:
							HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, 1);
							HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 0);
							HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 1);
							HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 1);
							display7SEG(modify_val % 10);
							break;
						case 2:
							HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, 1);
							HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 1);
							HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 0);
							HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 0);
							display7SEG(status - 10);
							break;
						default:
							HAL_GPIO_WritePin(E0_GPIO_Port, E0_Pin, 1);
							HAL_GPIO_WritePin(E1_GPIO_Port, E1_Pin, 1);
							HAL_GPIO_WritePin(E2_GPIO_Port, E2_Pin, 1);
							HAL_GPIO_WritePin(E3_GPIO_Port, E3_Pin, 1);
							break;
					}
				}
}
