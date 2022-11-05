/*
 * software_timer.h
 *
 *  Created on: Oct 29, 2022
 *      Author: NTV
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

#define TIMER_CYCLE 10

extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int duration);
void setTimer2(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
