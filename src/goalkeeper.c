#include "goalkeeper/goalkeeper.h"
#include "motion/motion.h"

void GkPrepKickoffHome(gk_data_t *data, gk_ret_t *ret)
{
    motion_data_t motion;
    motion.vel_x = 1;
    motion.vel_y = 1;
    motion.vel_th = 1;
    printf("GK_Prep_kickoff: %d %d\n", data->robot_x[data->robot_num], data->robot_y[data->robot_num]);
    printf("Ball data: %f %f\n", data->ball_x, data->ball_y);
    JalanManual(&motion);
    static uint16_t main_state;
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
    printf("GK_Start_kickoff: %d %d\n", data->robot_x[data->robot_num], data->robot_y[data->robot_num]);
}

void GkStop(gk_data_t *data, gk_ret_t *ret)
{
    printf("GK_Stop_kickoff\n");
}

void GkRun(gk_data_t *data, gk_ret_t *ret)
{
    printf("stat: %d \n", data->game_status);

    switch (data->game_status)
    {
    case PREP_KICKOFF_HOME:
        GkPrepKickoffHome(data, ret);
        break;
    case START_KICKOFF_HOME:
        GkKickoffHome(data, ret);
        break;
    case command_stop:
        GkStop(data, ret);
        break;
    }
}