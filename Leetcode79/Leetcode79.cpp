//
// Created by hans on 4/29/18.
//

#include "Leetcode79.h"

bool Leetcode79::exist(vector<vector<char>> &board, string word) {
    if (word.empty())
        return true;
    if (board.empty() || board[0].empty())
        return false;
    bool ans = false;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            helper(board, word, 0, word.size() - 1, i, j, ans);
        }
    }
    return ans;
}

void Leetcode79::helper(vector<vector<char>> &board, string word,
                        int begin, int end, int i, int j, bool &ans) {
    if (ans == true) {
        return;
    }
    if (word[begin] != board[i][j]) {
        return;
    } else {
        board[i][j] = '#';
        if (begin == end) {
            board[i][j] = word[begin];
            ans = true;
            return;
        }
        if (i + 1 < board.size())
            helper(board, word, begin + 1, end, i + 1, j, ans);
        if (i - 1 >= 0)
            helper(board, word, begin + 1, end, i - 1, j, ans);
        if (j + 1 < board[0].size())
            helper(board, word, begin + 1, end, i, j + 1, ans);
        if (j - 1 >= 0)
            helper(board, word, begin + 1, end, i, j - 1, ans);

        board[i][j] = word[begin];
    }
}

void Leetcode79::test79() {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    bool ans;
    ans = exist(board, "SEE");
    cout << "SEE->" << ans << endl;
    ans = exist(board, "ABCCED");
    cout << "ABCCEDABCCED->" << ans << endl;
    ans = exist(board, "ABCB");
    cout << "ABCB->" << ans << endl;

}
