#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#define EMPTY ' '
#define PLAYER_SYMBOL 'X'
#define COMPUTER_SYMBOL 'O'
#define BOARD_SIZE 9

void init_board(char board[BOARD_SIZE]);

void display_board(const char board[BOARD_SIZE]);

int ask_player_move(const char board[BOARD_SIZE]);

int computer_move(const char board[BOARD_SIZE]);

int has_won(const char board[BOARD_SIZE], char symbol);

int is_full(const char board[BOARD_SIZE]);

#endif