#include "goalkeeper/goalkeeper.h"

void gk_prep_kickoff_home(gk_data_t *data, gk_ret_t *ret)
{
    printf("GK_Prep_kickoff: %d %d\n", data->robot_x[data->robot_num], data->robot_y[data->robot_num]);
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

void gk_start_kickoff_home(gk_data_t *data, gk_ret_t *ret)
{
    printf("GK_Start_kickoff: %d %d\n", data->robot_x[data->robot_num], data->robot_y[data->robot_num]);
}

void gk_run(gk_data_t *data, gk_ret_t *ret)
{
    printf("stat: %d \n", data->game_status);

    switch (data->game_status)
    {
    case PREP_KICKOFF_HOME:
        gk_prep_kickoff_home(data, ret);
        break;
    case START_KICKOFF_HOME:
        gk_start_kickoff_home(data, ret);
        break;
    }
}