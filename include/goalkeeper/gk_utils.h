#ifndef GK_UTILS_H
#define GK_UTILS_H

#define preparation_kickoff_home 'K'
#define preparation_kickoff_away 'k'
#define preparation_freekick_home 'F'
#define preparation_freekick_away 'f'

#define command_stop 'S'
#define command_stop_2 ' '

//---Manual Commands
#define command_forward 'j'
#define command_backward 'n'
#define command_left 'b'
#define command_right 'm'
#define command_rotate_left '9'
#define command_rotate_right '0'

#define start_kickoff_home preparation_kickoff_home + 128
#define start_kickoff_away preparation_kickoff_away + 128
#define start_freekick_home preparation_freekick_home + 128
#define start_freekick_away preparation_freekick_away + 128

#define FIELD_X_1 800
#define FIELD_Y_1 1200

#define FIELD_X_1_2 FIELD_X_1 / 2
#define FIELD_Y_1_2 FIELD_Y_1 / 2

#endif