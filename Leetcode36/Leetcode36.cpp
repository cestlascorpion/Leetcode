//
// Created by hans on 18-4-24.
//

#include "Leetcode36.h"

bool Leetcode36::isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++i) {
        unordered_set<char> s;
        for (int j = 0; j < 9; ++j) {
            if (s.find(board[i][j]) != s.end())
                return false;
            if (board[i][j] != '.')
                s.insert(board[i][j]);
        }
        s.clear();
    }
    for (int i = 0; i < 9; ++i) {
        unordered_set<char> s;
        for (int j = 0; j < 9; ++j) {
            if (s.find(board[j][i]) != s.end())
                return false;
            if (board[j][i] != '.')
                s.insert(board[j][i]);
        }
        s.clear();
    }
    int offset_row = 0;
    int offset_col = 0;
    for (int i = 0; i < 9; ++i) {
        unordered_set<char> s;
        for (int m = 0; m < 3; ++m) {
            for (int n = 0; n < 3; ++n) {
                if (s.find(board[m + offset_row][n + offset_col]) != s.end())
                    return false;
                if (board[m + offset_row][n + offset_col] != '.')
                    s.insert(board[m + offset_row][n + offset_col]);
            }
        }
        if (offset_col == 6)
            offset_row += 3;
        offset_col = (offset_col + 3) % 9;
    }
    return true;
}

void Leetcode36::test36() {
    vector<vector<char>> board;
    vector<char> v1 = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    board.push_back(v1);
    vector<char> v2 = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    board.push_back(v2);
    vector<char> v3 = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    board.push_back(v3);
    vector<char> v4 = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    board.push_back(v4);
    vector<char> v5 = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    board.push_back(v5);
    vector<char> v6 = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    board.push_back(v6);
    vector<char> v7 = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    board.push_back(v7);
    vector<char> v8 = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    board.push_back(v8);
    vector<char> v9 = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    //[[".",".",".",".",".",".","5",".","."],
    // [".",".",".",".",".",".",".",".","."],
    // [".",".",".",".",".",".",".",".","."],

    // ["9","3",".",".","2",".","4",".","."],
    // [".",".","7",".",".",".","3",".","."],
    // [".",".",".",".",".",".",".",".","."],

    // [".",".",".","3","4",".",".",".","."],
    // [".",".",".",".",".","3",".",".","."],
    // [".",".",".",".",".","5","2",".","."]]
    board.push_back(v9);
    if (isValidSudoku(board))
        cout << "it's a Valid Sudoku." << endl;
    else
        cout << "it's not a Valid Sudoku." << endl;
};
