/*
 * fsm_automatic.h
 *
 *  Created on: 27 Oct 2024
 *      Author: PC
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "button.h"
#include "software_timer.h"
#include "led_traffic.h"
#include "Component_1.h"
#include "Component.h"
#include "fsm_setting.h"

extern int bool;
extern int counter;
extern int i_1, j_1, t_1;
extern int i_2, j_2, t_2;
extern int test, random, dem;
extern int max_Red, max_Yellow, max_Green;
extern int prev_max_Red, prev_max_Yellow, prev_max_Green;

void case1();

int case2(int mode,int a,
		GPIO_TypeDef* D0_PORT, uint16_t D0_PIN, GPIO_TypeDef* D1_PORT, uint16_t D1_PIN,
		GPIO_TypeDef* D2_PORT, uint16_t D2_PIN, GPIO_TypeDef* D3_PORT, uint16_t D3_PIN,
		GPIO_TypeDef* D4_PORT, uint16_t D4_PIN, GPIO_TypeDef* D5_PORT, uint16_t D5_PIN);

#endif /* INC_FSM_AUTOMATIC_H_ */
