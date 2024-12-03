/*
 * fsm_setting.h
 *
 *  Created on: 27 Oct 2024
 *      Author: PC
 */

#ifndef INC_FSM_SETTING_H_
#define INC_FSM_SETTING_H_

#include "button.h"
#include "software_timer.h"
#include "led_traffic.h"
#include "Component_1.h"
#include "Component.h"
#include "fsm_automatic.h"

extern int mode, en0, en1, en2, en3;

void turn_Led7SEG();
void setup_Led7SEG();
void fsm_setting();

#endif /* INC_FSM_SETTING_H_ */
