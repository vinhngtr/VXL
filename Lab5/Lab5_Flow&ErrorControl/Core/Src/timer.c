/*
 * timer.c
 *
 *  Created on: 16 Dec 2022
 *      Author: NTV
 */
#include "main.h"
#include "timer.h"

int timeout_flag = 0;
int timeout_counter = 0;
int TIMER_CYCLE = 10;

void setTimer() {
	timeout_counter = TIMEOUT_VALUE / TIMER_CYCLE;
	timeout_flag = 0;
}
void timerInit() {
	setTimer(TIMER_INIT);
}
void timer_run() {
	if (timeout_counter > 0) {
		timeout_counter--;
		if (timeout_counter == 0) timeout_flag = 1;
	}
}
