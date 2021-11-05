#pragma once
enum board {board_rows = 5, board_columns = 5, cord3 = 3, cord2 = 2, cord1 = 1};
enum results { success = 0, user_quit = 1, coord_extraction_success = 2, turn_userquit = 3, valid_value = 4, game_draw = 5, play_userquit = 6, Inc_cmdargs = 7};
enum cmdargs {lab3 = 0, input_string = 1, correct_number_args = 2};

int usage_message(char* name);
