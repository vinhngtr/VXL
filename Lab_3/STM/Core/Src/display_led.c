/*
 * display_led.c
 *
 *  Created on: Nov 14, 2022
 *      Author: NTV
 */

#include "main.h"
#include "display_led.h"
#include "setTimer.h"

uint16_t RED[2] = { GPIO_PIN_7, GPIO_PIN_10 };
uint16_t YEL[2] = { GPIO_PIN_8, GPIO_PIN_11 };
uint16_t GRE[2] = { GPIO_PIN_9, GPIO_PIN_12 };

//time that one led can run
int LED_TIME[3] = {5000,3000,2000};
int currentState[2] = {0,1};
int currentTimer[2] = {0,0};

void clear_vertical() {
	HAL_GPIO_WritePin( GPIOB, GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9,
			GPIO_PIN_SET);
}
void clear_horizontal() {
	HAL_GPIO_WritePin( GPIOB, GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12,
			GPIO_PIN_SET);
}
void clearLED() {
	clear_vertical();
	clear_horizontal();
}


void currentState_update(int index) {
	//0 for Ver, 1 for Ho
	currentTimer[index] = LED_TIME[currentState[index]];
	currentState[index] = currentState[index] + 1;
	if(currentState[index] >= 3) currentState[index] = 0;
}
void vertical_processing() {
	clear_vertical();
	switch (currentState[0]) {
	case RED_IDX:
		HAL_GPIO_WritePin( GPIOB, RED[0], GPIO_PIN_RESET);
		break;
	case GRE_IDX:
		HAL_GPIO_WritePin( GPIOB, GRE[0], GPIO_PIN_RESET);
		break;
	case YEL_IDX:
		HAL_GPIO_WritePin( GPIOB, YEL[0], GPIO_PIN_RESET);
		break;
	}
}
void horizontal_processing() {
	clear_horizontal();
	switch (currentState[1]) {
	case GRE_IDX:
		HAL_GPIO_WritePin( GPIOB, GRE[1], GPIO_PIN_RESET);
		break;
	case YEL_IDX:
		HAL_GPIO_WritePin( GPIOB, YEL[1], GPIO_PIN_RESET);
		break;
	case RED_IDX:
		HAL_GPIO_WritePin( GPIOB, RED[1], GPIO_PIN_RESET);
		break;
	}
}


//because when press the add button => both led in two side change time => we just need one

void SHOW_LED(){
	if(timer1_flag == 1) {
		vertical_processing();
		currentState_update(0);
		setTimer1(currentTimer[0]); //setTimer for run
	}
	if(timer2_flag == 1){
		horizontal_processing() ;
		currentState_update(1) ;
		setTimer2(currentTimer[1]);
	}
}

void update_led(int mode) {
	currentState[0] = 0;
	currentState[1] = 1;
	timer1_flag = 1;
	timer2_flag = 1;
	switch (mode) {
	case 0: // if MODE = 0 , do nothing
		return;
	case 1: // RED
	case 3: // GREEN
		LED_TIME[RED_IDX] = LED_TIME[RED_IDX] + (TERM * 1000);
		LED_TIME[GRE_IDX] = LED_TIME[GRE_IDX] + (TERM * 1000);
		break;
	case 2: // YELLOW
		LED_TIME[YEL_IDX] = LED_TIME[YEL_IDX] + (TERM * 1000);
		LED_TIME[RED_IDX] = LED_TIME[RED_IDX] + (TERM * 1000);
		break;
	}
}
