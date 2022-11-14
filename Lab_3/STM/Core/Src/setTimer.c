/*
 * setTimer.c
 *
 *  Created on: Nov 14, 2022
 *      Author: NTV
 */

#include "setTimer.h"

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int timer7SEG_counter = 0;
int timer7SEG_flag = 0;



void setTimer1(int duration) {
	timer1_counter = duration/TIMER_CYCLE;
	timer1_flag = 0;
}
void setTimer2(int duration) {
	timer2_counter = duration/TIMER_CYCLE;
	timer2_flag = 0;
}
void setTimer7SEG(int duration) {
	timer7SEG_counter = duration/TIMER_CYCLE;
	timer7SEG_flag = 0;
}


void timerRun() {
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}
	if (timer2_counter > 0) {
		timer2_counter--;
		if (timer2_counter <= 0) {
			timer2_flag = 1;
		}
	}
	if (timer7SEG_counter > 0) {
		timer7SEG_counter--;
		if (timer7SEG_counter <= 0) {
			timer7SEG_flag = 1;
		}
	}
}
