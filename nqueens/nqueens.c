#include <stdio.h>

#define N 8 

int idx(int row, int col) {
    return col + N * row;
}

int is_attacking_diag(int* board, int row, int col, int dx, int dy) {
    while (1) {
        row += dx;
        col += dy;
        if (row < 0 || N <= row || col < 0 || N <= col) {
            break;
        }
        if (board[idx(row, col)]) {
            return 1;
        }
    }
    return 0;
}

int is_attacking(int* board, int row, int col) {
    for (int i = 0; i < N; ++i) {
        if (board[idx(i, col)] || board[idx(row, i)]) {
            return 1;
        }
    }
    return is_attacking_diag(board, row, col, 1, 1)
        || is_attacking_diag(board, row, col, 1, -1)
        || is_attacking_diag(board, row, col, -1, 1)
        || is_attacking_diag(board, row, col, -1, -1);
}

void print_board(int* board) {
    for (int col = 0; col < N; ++col) {
        for (int row = 0; row < N; ++row) {
            putchar(board[idx(row, col)] ? 'O' : '.');
        }
        putchar('\n');
    }
}

void solve(int* board, int* num_solutions, int row) {
    for (int col = 0; col < N; ++col) {
        if (!is_attacking(board, row, col)) {
            board[idx(row, col)] = 1;
            if (row == N - 1) {
                printf("#%d\n", ++*num_solutions);
                print_board(board);
                putchar('\n');
            }
            solve(board, num_solutions, row + 1);
            for (int i = idx(row, col); i < N * N; ++i) {
                board[i] = 0;
            }
        }
    }
}

int main(void) {
    int board[N * N] = {0};
    int num_solutions = 0;
    solve(board, &num_solutions, 0);
    return 0;
}
