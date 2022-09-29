/**
 * @author Wildan IRIS ITS
 * @brief This is program core for Goalkeeper decision maker
 * Pre-request data that will be calculated to get a decision
 * @return This program will return an action condition
 * */

#ifndef GOALKEEPER_H
#define GOALKEEPER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "goalkeeper/gk_utils.h"

    // Data to be proceed to make robot's decision
    typedef struct gk_data_tag
    {
        int16_t robot_x[6];
        int16_t robot_y[6];
        int16_t robot_th[6];
        uint8_t robot_num;
        int16_t ball_x;
        int16_t ball_y;
        char obs[15];
        uint8_t total_obs;
        uint8_t game_status;

    } gk_data_t;

    typedef struct gk_ret_tag
    {
        uint8_t act_type;
        int16_t target_x;
        int16_t target_y;
        int16_t target_th;
        int16_t dist_to_target;
        int16_t angle_to_target;
        int8_t vel_x_gain;
        int8_t vel_y_gain;
        int8_t vel_th_gain;

    } gk_ret_t;

    void gk_prep_kickoff_home(gk_data_t *data, gk_ret_t *ret);
    void gk_start_kickoff_home(gk_data_t *data, gk_ret_t *ret);

    void gk_run(gk_data_t *data, gk_ret_t *ret);

#ifdef __cplusplus
}
#endif

#endif