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
#include "goalkeeper/BS_utils.h"

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

    void gk_prep_kickoff_home(gk_data_t *data, uint8_t *ret);
    void gk_start_kickoff_home(gk_data_t *data, uint8_t *ret);

    void gk_run(gk_data_t *data, uint8_t *ret);

#ifdef __cplusplus
}
#endif

#endif