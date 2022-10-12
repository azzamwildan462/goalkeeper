/**
 * @author Wildan IRIS ITS
 * @brief This is program core for Goalkeeper decision maker
 * Pre-request data that will be calculated to get a decision
 * @return This program will return an action condition
 * */

#ifndef GOALKEEPER_H
#define GOALKEEPER_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "multirole_func/multirole_func.h"
#include "motion/motion.h"

extern float pos_robot[3];

//=--------Global--------=//
extern uint8_t game_status;
extern uint8_t n_active_robot;
static uint16_t game_sub_status;
extern uint8_t n_active_robot;
extern uint8_t style;

bool PreparationKickOff();

void GameMain();


#endif