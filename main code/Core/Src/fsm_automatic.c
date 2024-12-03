/*
 * fsm_automatic.c
 *
 *  Created on: 27 Oct 2024
 *      Author: PC
 */

#include "fsm_automatic.h"

int bool = 0;
int counter = 0, counter2 = 1;
int i_1 = 5, j_1 = 2, t_1 = 3;
int i_2 = 5, j_2 = 2, t_2 = 3;
int test = 1, random = 1, dem = 2;
int max_Red = 5, max_Yellow = 2, max_Green = 3, turn = 0;
int prev_max_Red = 5, prev_max_Yellow = 2, prev_max_Green = 3;

void Reset(){
	en0 = 1; en1 = 0; en2 = 1; en3 = 0;
	i_1 = max_Red;
	j_1 = max_Yellow;
	t_1 = max_Green;
	i_2 = max_Red;
	j_2 = max_Yellow;
	t_2 = max_Green;
	test = 1; random = 1; dem = 2;
	turn = 0;
	counter = 0, counter2 = 1;
	bool = 0;
}

void case1() {
	switch(counter){
	case 0:
		LED_RED_1();
		if (random == 1) {
			display7SEG(i_1 / 10);
		} else {
			display7SEG(i_1 % 10);
		}
		if(dem == 0){
			i_1--;
		}
		if(i_1 == 0) {
			i_1 = max_Red;
			counter++;
		}
		break;
	case 1:
		LED_GREEN_1();
		if (random == 1) {
			display7SEG(t_1 / 10);
		} else {
			display7SEG(t_1 % 10);
		}
		if(dem == 0){
			t_1--;
		}
		if(t_1 == 0) {
			t_1 = max_Green;
			counter++;
		}
		break;
	case 2:
		LED_YELLOW_1();
		if (random == 1) {
			display7SEG(j_1 / 10);
		} else {
			display7SEG(j_1 % 10);
		}
		if(dem == 0){
			j_1--;
		}
		if(j_1 == 0) {
			j_1 = max_Yellow;
			counter = 0;
		}
		break;
	}

	switch(counter2){
	case 0:
		LED_RED_2();
		if (random == 1) {
			display7SEG_1(i_2 / 10);
		} else {
			display7SEG_1(i_2 % 10);
		}
		if(dem == 0){
			i_2--;
		}
		if(i_2 == 0) {
			i_2 = max_Red;
			counter2++;
		}
		break;
	case 1:
		LED_GREEN_2();
		if (random == 1) {
			display7SEG_1(t_2 / 10);
		} else {
			display7SEG_1(t_2 % 10);
		}
		if(dem == 0){
			t_2--;
		}
		if(t_2 == 0) {
			t_2 = max_Green;
			counter2++;
		}
		break;
	case 2:
		LED_YELLOW_2();
		if (random == 1) {
			display7SEG_1(j_2 / 10);
		} else {
			display7SEG_1(j_2 % 10);
		}
		if(dem == 0){
			j_2--;
		}
		if(j_2 == 0) {
			j_2 = max_Yellow;
			counter2 = 0;
		}
		break;
	}
}

int case2(int mode,int a,
		GPIO_TypeDef* D0_PORT, uint16_t D0_PIN, GPIO_TypeDef* D1_PORT, uint16_t D1_PIN,
		GPIO_TypeDef* D2_PORT, uint16_t D2_PIN, GPIO_TypeDef* D3_PORT, uint16_t D3_PIN,
		GPIO_TypeDef* D4_PORT, uint16_t D4_PIN, GPIO_TypeDef* D5_PORT, uint16_t D5_PIN){
	setup_Led7SEG();

	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);

	HAL_GPIO_WritePin(D0_PORT, D0_PIN, en0);
	HAL_GPIO_WritePin(D1_PORT, D1_PIN, en0);
	HAL_GPIO_WritePin(D2_PORT, D2_PIN, 0);
	HAL_GPIO_WritePin(D3_PORT, D3_PIN, 0);
	HAL_GPIO_WritePin(D4_PORT, D4_PIN, 0);
	HAL_GPIO_WritePin(D5_PORT, D5_PIN, 0);
	display7SEG_1(mode + 1);

	if(button_flag[1] == 1){
	  button_flag[1] = 0;
	  a++;
	}
	if(button_flag[2] == 1){
	  button_flag[2] = 0;
	  switch(mode){
	  case 1:
		  prev_max_Red = a;
		  break;
	  case 2:
		  prev_max_Yellow = a;
		  break;
	  case 3:
		  prev_max_Green = a;
		  break;
	  }
	}
	if(button_flag[3] == 1){
	  button_flag[3] = 0;
	  a--;
	}
	if(a > 99) a = 0;
	if(a < 0) a = 99;
	if(random == 1)
	  display7SEG(a / 10);
	else
	  display7SEG(a % 10);
	return a;
}
