/*
 * fsm.h
 *
 *  Created on: 16 Dec 2022
 *      Author: NTV
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

extern void resetBuffer();
extern int timeout_flag;
extern uint8_t ERROR_CODE;

void uart_communiation_fsm();
void command_parser_fsm();

#endif /* INC_FSM_H_ */
