#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

const int SIZE = 3;

bool is_board_full(const char board[SIZE][SIZE]);
void print_board(const char board[SIZE][SIZE]);
bool check_win(const char board[SIZE][SIZE], char player);
int get_random_move(const char board[SIZE][SIZE]);

int main1() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int player = 1;
    while (true) {
        print_board(board);

        if (player == 1) {
            int x, y;
            std::cout << "Player " << player << ", enter your move (row and column)" << std::endl;
            printf("Row: ");
            std::cin >> x;
            printf("Column: ");
            std::cin>> y;

            if (board[x - 1][y - 1] != ' ') {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }

            if (player == 1) {
                board[x - 1][y - 1] = 'X';
            } else {
                board[x - 1][y - 1] = 'O';
            }

            if (check_win(board, 'X')) {
                print_board(board);
                std::cout << "Player X wins!" << std::endl;
                break;
            } else if (check_win(board, 'O')) {
                print_board(board);
                std::cout << "Player O wins!" << std::endl;
                break;
            } else if (is_board_full(board)) {
                print_board(board);
                std::cout << "It's a draw!" << std::endl;
                break;
            }

            int bot_move = get_random_move(board);
            int bot_x = bot_move / 3;
            int bot_y = bot_move % 3;

            if (board[bot_x][bot_y] != ' ') {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }

            board[bot_x][bot_y] = 'O';

            if (check_win(board, 'O')) {
                print_board(board);
                std::cout << "Player O wins!" << std::endl;
                break;
            } else if (is_board_full(board)) {
                print_board(board);
                std::cout << "It's a draw!" << std::endl;
                break;
            }

            board[bot_x][bot_y] = 'O';

            if (check_win(board, 'O')) {
                print_board(board);
                std::cout << "Player O wins!" << std::endl;
                break;
            } else if (is_board_full(board)) {
                print_board(board);
                std::cout << "It's a draw!" << std::endl;
                break;
            }

            player = 1;
        }
    }

    return 0;
}

bool is_board_full(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}




void print_board(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}




bool check_win(const char board[SIZE][SIZE], char player) {
    // Check rows
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}




int get_random_move(const char board[SIZE][SIZE]) {
    srand(time(0));

    int empty_cells = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                empty_cells++;
            }
        }
    }

    if (empty_cells == 0) {
        return -1;
    }

    int random_index = rand() % empty_cells;
    int move = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                if (random_index == 0) {
                    move = i * 3 + j;
                    break;
                }
                random_index--;
            }
        }
    }

    return move;
}