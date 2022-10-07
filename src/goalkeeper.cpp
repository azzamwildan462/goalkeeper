#include "goalkeeper/goalkeeper.h"
#include "motion/motion.h"

motion_data_t motion;
motion_return_t motion_ret;

void GkPrepKickoffHome(gk_data_t *data, gk_ret_t *ret)
{
    // motion.vel_x = 10;
    // motion.vel_y = 10;
    motion.vel_th = 1;
    motion.vel_position = 10;
    motion.acceleration = 2;
    motion.target_x = 0;
    motion.target_y = 100;
    motion.target_th = 0;
    

    static uint8_t stat_preparation_kickoff_home;
    
    printf("Stat preparation kickoff home: %d\n", stat_preparation_kickoff_home);

    switch (stat_preparation_kickoff_home)
    {
    case 0:
        if (PositionAngularMotion(&motion, &motion_ret))
        {
            stat_preparation_kickoff_home = 1;
        }
        break;

    case 1:
        GkStop(data, ret);

    default:
        break;
    }
    // PositionAngularMotion(&motion, &motion_ret, data);
    // printf("Motion data: %d %d %d\n", motion_ret.vx, motion_ret.vy, motion_ret.vth);
    static uint16_t main_state;
    ret->vel_x_gain = motion_ret.vx;
    ret->vel_y_gain = motion_ret.vy;
    ret->vel_th_gain = motion_ret.vth;
    switch (main_state)
    {
    case 0:
        if (data->ball_y > FIELD_Y_1_2)
            ret->act_type = 0;
        else
        {
            ret->act_type = 10;
            ret->target_x = data->ball_x;
            ret->target_y = data->robot_y[data->robot_num];
        }
        break;
    }
}

void GkKickoffHome(gk_data_t *data, gk_ret_t *ret)
{
    // printf("GK_Start_kickoff: %d %d\n", data->robot_x[data->robot_num], data->robot_y[data->robot_num]);
}

void GkStop(gk_data_t *data, gk_ret_t *ret)
{
    printf("Masuk GK Stop di posisi: %d %d %d\n", pos_robot[0], pos_robot[1], pos_robot[2]);
    // printf("GK_Stop: %d %d\n", data->robot_x[data->robot_num], data->robot_y[data->robot_num]);
    motion.vel_x = 0;
    motion.vel_y = 0;
    motion.vel_th = 0;
    ManualMotion(&motion, &motion_ret);
    ret->vel_x_gain = motion_ret.vx;
    ret->vel_y_gain = motion_ret.vy;
    ret->vel_th_gain = motion_ret.vth;
    // printf("Motion data: %d %d %d\n", motion_ret.vx, motion_ret.vy, motion_ret.vth);
}

/**
 * @param switch_mode: 1: Forward | 2: Backward | 3: Left | 4: Right | 5: Rotate Left | 6: Rotate Right
 */
void GkManual(gk_data_t *data, gk_ret_t *ret, uint8_t switch_mode)
{
    // printf("GK_Manual: %d %d\n", data->robot_x[data->robot_num], data->robot_y[data->robot_num]);

    if (switch_mode == 1)
    {
        motion.vel_x = 0;
        motion.vel_y = 10;
        motion.vel_th = 0;
    }
    else if (switch_mode == 2)
    {
        motion.vel_x = 0;
        motion.vel_y = -10;
        motion.vel_th = 0;
    }
    else if (switch_mode == 3)
    {
        motion.vel_x = -10;
        motion.vel_y = 0;
        motion.vel_th = 0;
    }
    else if (switch_mode == 4)
    {
        motion.vel_x = 10;
        motion.vel_y = 0;
        motion.vel_th = 0;
    }
    else if (switch_mode == 5)
    {
        motion.vel_x = 0;
        motion.vel_y = 0;
        motion.vel_th = 10;
    }
    else if (switch_mode == 6)
    {
        motion.vel_x = 0;
        motion.vel_y = 0;
        motion.vel_th = -10;
    }
    printf("Motion data: %d %d %d\n", motion.vel_x, motion.vel_y, motion.vel_th);
    motion.acceleration = 2;
    ManualMotion(&motion, &motion_ret);
    ret->vel_x_gain = motion_ret.vx;
    ret->vel_y_gain = motion_ret.vy;
    ret->vel_th_gain = motion_ret.vth;
    // printf("Motion data: %d %d %d\n", motion_ret.vx, motion_ret.vy, motion_ret.vth);
}

void GkRun(gk_data_t *data, gk_ret_t *ret)
{
    // printf("stat: %d \n", data->game_status);

    switch (data->game_status)
    {
    case preparation_kickoff_home:
        GkPrepKickoffHome(data, ret);
        break;
    case start_kickoff_home:
        GkKickoffHome(data, ret);
        break;
    case command_stop:
        GkStop(data, ret);
        break;
    case command_stop_2:
        GkStop(data, ret);
        break;
    case command_forward:
        GkManual(data, ret, 1);
        break;
    case command_backward:
        GkManual(data, ret, 2);
        break;
    case command_left:
        GkManual(data, ret, 3);
        break;
    case command_right:
        GkManual(data, ret, 4);
        break;
    case command_rotate_left:
        GkManual(data, ret, 5);
        break;
    case command_rotate_right:
        GkManual(data, ret, 6);
        break;
    }
}