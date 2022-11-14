/*
 * display7SEG.c
 *
 *  Created on: Nov 14, 2022
 *      Author: NTV
 */

#include "main.h"
#include "display7SEG.h"
#include "setTimer.h"
#include "button.h"

const int MAX_7SEG = 4;
int index_7SEG = 0;
int TVAL_7SEG[2] = { 0, 0 };
int DISPLAY_7SEG[4] = { 0, 0, 0, 0 };
int TIME_7SEG[4] = { GPIO_PIN_7, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10 };


void clear7SEG() {
	HAL_GPIO_WritePin( GPIOA, GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 |
	GPIO_PIN_10, GPIO_PIN_SET);

	HAL_GPIO_WritePin( GPIOB, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 |
	GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6, GPIO_PIN_SET);
}


void update_tval() {
	DISPLAY_7SEG[0] = TVAL_7SEG[0] / 10;
	DISPLAY_7SEG[1] = TVAL_7SEG[0] % 10;
	DISPLAY_7SEG[2] = TVAL_7SEG[1] / 10;
	DISPLAY_7SEG[3] = TVAL_7SEG[1] % 10;
}
void displayValue() {
  TVAL_7SEG[0] = TERM;
}
void displayMode() {
	TVAL_7SEG[1] = MODE;
}

void display7SEG(int idx, int num) {
	HAL_GPIO_WritePin( GPIOA, TIME_7SEG[index_7SEG], GPIO_PIN_RESET);
	char led7seg[10] = { 0x40, 0x79, 0x24, 0x30, 0x19, 0x92, 0x02, 0x78, 0x0,
				0x10 };
	for (int i = 0; i < 7; i++) {
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, (led7seg[num] >> i) & 1);
	}
}

void show7SEG() {
	if(timer7SEG_flag == 1) {
		clear7SEG();
		displayValue();
		displayMode();
		update_tval();
		display7SEG(index_7SEG,DISPLAY_7SEG[index_7SEG]);
		index_7SEG++;
		if (index_7SEG >= MAX_7SEG)
		index_7SEG = 0;
		setTimer7SEG(250);
	}

}

