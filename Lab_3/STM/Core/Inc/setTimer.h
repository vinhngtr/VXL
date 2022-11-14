/*
 * setTimer.h
 *
 *  Created on: Nov 14, 2022
 *      Author: NTV
 */

#ifndef INC_SETTIMER_H_
#define INC_SETTIMER_H_

#define TIMER_CYCLE  10

extern int timer1_flag;
extern int timer2_flag;
extern int timer7SEG_flag;




void setTimer1(int duration);
void setTimer2(int duration);
void setTimer7SEG(int duration);


void timerRun();


#endif /* INC_SETTIMER_H_ */
