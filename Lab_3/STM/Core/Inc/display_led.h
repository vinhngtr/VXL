/*
 * display_led.h
 *
 *  Created on: Nov 14, 2022
 *      Author: NTV
 */

#ifndef INC_DISPLAY_LED_H_
#define INC_DISPLAY_LED_H_

#include "button.h"

#define RED_IDX 0
#define GRE_IDX 1
#define YEL_IDX 2

extern int LED_TIME[3];

void SHOW_LED();
void update_led(int MODE);


#endif /* INC_DISPLAY_LED_H_ */
