//
// Created by Wang on 2019/11/22.
//

#include "Leetcode289cn.h"

void Leetcode289cn::gameOfLife(vector<vector<int>> &board) {
    if (board.empty()) {
        return;
    }
    int row = board.size();
    if (board[0].empty()) {
        return;
    }
    int col = board[0].size();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            mark(board, i, j, row, col);
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            change(board, i, j);
        }
    }

}

void Leetcode289cn::mark(vector<vector<int>> &board, int i, int j, int row, int col) {
    int alive = 0;
    if (valid(i - 1, j - 1, row, col)) {
        if (board[i - 1][j - 1] > 0) ++alive;
    }
    if (valid(i - 1, j, row, col)) {
        if (board[i - 1][j] > 0) ++alive;
    }
    if (valid(i - 1, j + 1, row, col)) {
        if (board[i - 1][j + 1] > 0) ++alive;
    }
    if (valid(i, j - 1, row, col)) {
        if (board[i][j - 1] > 0) ++alive;
    }
    if (valid(i, j + 1, row, col)) {
        if (board[i][j + 1] > 0) ++alive;
    }
    if (valid(i + 1, j - 1, row, col)) {
        if (board[i + 1][j - 1] > 0) ++alive;
    }
    if (valid(i + 1, j, row, col)) {
        if (board[i + 1][j] > 0) ++alive;
    }
    if (valid(i + 1, j + 1, row, col)) {
        if (board[i + 1][j + 1] > 0) ++alive;
    }

    if (board[i][j] == 0) {
        if (alive == 3) board[i][j] = -1;
    } else {
        if (alive < 2 || alive > 3) board[i][j] = 2;
    }
}

void Leetcode289cn::change(vector<vector<int>> &board, int i, int j) {
    if (board[i][j] == -1) {
        board[i][j] = 1;

    } else if (board[i][j] == 2) {
        board[i][j] = 0;
    }
}

bool Leetcode289cn::valid(int i, int j, int row, int col) {
    return i >= 0 && i < row && j >= 0 && j < col;
}