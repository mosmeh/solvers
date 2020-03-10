#include <array>
#include <iostream>

constexpr int SIZE = 9;
constexpr int NUM_CELLS = SIZE * SIZE;
constexpr int BLOCK_SIZE = 3;

struct Board {
    std::array<int, NUM_CELLS> cells;

    bool canPut(int i, int n) const {
        if (cells[i] != 0) {
            return false;
        }

        const int x = i % SIZE;
        const int y = i / SIZE;
        for (int j = 0; j < SIZE; ++j) {
            if (cells[j + y * SIZE] == n) {
                return false;
            }
            if (cells[x + j * SIZE] == n) {
                return false;
            }
        }

        const int bx = x / BLOCK_SIZE;
        const int by = y / BLOCK_SIZE;
        for (int i = bx * BLOCK_SIZE; i < (bx + 1) * BLOCK_SIZE; ++i) {
            for (int j = by * BLOCK_SIZE; j < (by + 1) * BLOCK_SIZE; ++j) {
                if (cells[i + j * SIZE] == n) {
                    return false;
                }
            }
        }

        return true;
    }

    int findNextEmptyCell(int i) const {
        while (i < NUM_CELLS && cells[i] != 0) {
            ++i;
        }
        return i;
    }

    void print() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (cells[j + i * SIZE] == 0) {
                    std::cout << '.';
                } else {
                    std::cout << cells[j + i * SIZE];
                }
            }
            std::cout << std::endl;
        }
    }
};

void solve(const Board& board, int i) {
    for (int n = 1; n <= 9; ++n) {
        if (board.canPut(i, n)) {
            Board next = board;
            next.cells[i] = n;
            const int nextI = next.findNextEmptyCell(i);
            if (nextI == NUM_CELLS) {
                next.print();
                exit(0);
            }
            solve(next, nextI);
        }
    }
}

int main() {
    Board initBoard;
    char x;
    for (int i = 0; i < NUM_CELLS; ++i) {
        std::cin.get(x);
        if (x == EOF) {
            return 1;
        }
        if (isdigit(x)) {
            initBoard.cells[i] = x - '0';
        } else if (x == '.') {
            initBoard.cells[i] = 0;
        } else {
            return 1;
        }
    }

    initBoard.print();
    std::cout << std::endl;

    solve(initBoard, initBoard.findNextEmptyCell(0));

    std::cout << "not solvable" << std::endl;
    return 1;
}
