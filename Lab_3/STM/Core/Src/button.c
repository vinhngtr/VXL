/*
 * button.c
 *
 *  Created on: Nov 14, 2022
 *      Author: NTV
 */

#include "button.h"
#include "display_led.h"


int buttonN_flag[4] = { 0 };

//signal button pressed
int buttonN_PIN[4] = { GPIO_PIN_12 , GPIO_PIN_13 , GPIO_PIN_14 , GPIO_PIN_15 };

int MODE = 0; // mode of button
int TERM = 0; //time to add

int KeyReg0[4] = {NORMAL_STATE};
int KeyReg1[4] = {NORMAL_STATE};
int KeyReg2[4] = {NORMAL_STATE};

int KeyReg3[4] = {NORMAL_STATE};
int TimerForKeyPress[4] = {100};


int isButtonNPressed(int index) {
	if (buttonN_flag[index] == 1) {
		buttonN_flag[index] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int index) {
	buttonN_flag[index] = 1;
}

void button_processing() {
	// Button Mode: press to change mode
	if (isButtonNPressed(0) == 1) {
		MODE++;
		if (MODE >= MAX_MODE)
			MODE = 0;
	}
	// Button Add: press to add time
	if (isButtonNPressed(1) == 1) {
		TERM++;
	}
	// Button Confirm
	if (isButtonNPressed(2) == 1) {
		if (TERM != 0) {
			update_led(MODE);
			TERM = 0;
		} else
			MODE = 0;
	}
	//Button Reset
	if (isButtonNPressed(3) == 1) {
		MODE = 0;
		TERM = 0;
	}
}


void getKeyInput() {
	for (int i = 0; i < 4; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(GPIOA, buttonN_PIN[i]);
		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg3[i] != KeyReg2[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE) {
					//TODO
					subKeyProcess(i);
					TimerForKeyPress[i] = 100;
				}
			} else {
				TimerForKeyPress[i]--;
				if (TimerForKeyPress[i] == 0) {
					//TODO
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}
