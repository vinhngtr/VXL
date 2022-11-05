/*
 * fsm_simple_buttons_run.c
 *
 *  Created on: Nov 6, 2022
 *      Author: NTV
 */

#include "fsm_simple_buttons_run.h"
//int COUNTER = 0;
void fsm_simple_buttons_run (){
//	int COUNTER = 0;
	if (isButton1Pressed() == 1) {
		COUNTER = 0;
	}
	if (isButton2Pressed() == 1) {
		COUNTER++;
		if(COUNTER > 9) COUNTER = 0;
	}
	if (isButton3Pressed() == 1) {
		COUNTER--;
		if(COUNTER < 0) COUNTER = 9;
	}
}
