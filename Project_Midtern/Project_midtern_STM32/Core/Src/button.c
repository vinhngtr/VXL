/*
 * button.c
 *
 *  Created on: Oct 28, 2022
 *      Author: NTV
 */

#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int KeyReg01 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;
int KeyReg21 = NORMAL_STATE;

int KeyReg02 = NORMAL_STATE;
int KeyReg12 = NORMAL_STATE;
int KeyReg22 = NORMAL_STATE;

int KeyReg03 = NORMAL_STATE;
int KeyReg13 = NORMAL_STATE;
int KeyReg23 = NORMAL_STATE;

int KeyReg31 = NORMAL_STATE;
int KeyReg32 = NORMAL_STATE;
int KeyReg33 = NORMAL_STATE;

int TimerForKeyPress = 300;

int isButton1Pressed() {
	if(button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed() {
	if(button2_flag == 1) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed() {
	if(button3_flag == 1) {
		button3_flag = 0;
		return 1;
	}
	return 0;
}


void subKey1Process() {
	button1_flag = 1;
}
void subKey2Process() {
	button2_flag = 1;
}
void subKey3Process() {
	button3_flag = 1;
}

void getKey1Input() {
	KeyReg01 = KeyReg11;
	KeyReg11 = KeyReg21;
	KeyReg21 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
	if((KeyReg01 == KeyReg11) && (KeyReg11 == KeyReg21)) {
		if(KeyReg31 != KeyReg21) {
			KeyReg31 = KeyReg21;
			if(KeyReg21 == PRESSED_STATE) {
				//TODO
				subKey1Process();
				TimerForKeyPress = 300;
			}
		}else {
			TimerForKeyPress--;
			if(TimerForKeyPress == 0) {
				//TODO
				if(KeyReg21 == PRESSED_STATE){
						subKey1Process();
					}
						TimerForKeyPress = 100;

			}
		}
	}
}

void getKey2Input() {
	KeyReg02 = KeyReg12;
	KeyReg12 = KeyReg22;
	KeyReg22 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
	if((KeyReg02 == KeyReg12) && (KeyReg12 == KeyReg22)) {
		if(KeyReg32 != KeyReg22) {
			KeyReg32 = KeyReg22;
			if(KeyReg22 == PRESSED_STATE) {
				//TODO
				subKey2Process();
				TimerForKeyPress = 300;
			}
		}else {
			TimerForKeyPress--;
			if(TimerForKeyPress == 0) {
				//TODO
				if(KeyReg22 == PRESSED_STATE){
						subKey2Process();
					}
						TimerForKeyPress = 100;

			}
		}
	}
}

void getKey3Input() {
	KeyReg03 = KeyReg13;
	KeyReg13 = KeyReg23;
	KeyReg23 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
	if((KeyReg03 == KeyReg13) && (KeyReg13 == KeyReg23)) {
		if(KeyReg33 != KeyReg23) {
			KeyReg33 = KeyReg23;
			if(KeyReg23 == PRESSED_STATE) {
				//TODO
				subKey3Process();
				TimerForKeyPress = 300;
			}
		}else {
			TimerForKeyPress--;
			if(TimerForKeyPress == 0) {
				//TODO
				if(KeyReg23 == PRESSED_STATE){
						subKey3Process();
					}
						TimerForKeyPress = 100;

			}
		}
	}
}

