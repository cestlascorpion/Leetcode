//
// Created by hans on 4/28/18.
//

#include "Leetcode17.h"

vector<string> Leetcode17::letterCombinations(string digits) {
    vector<string> ans;
    if (digits.empty())
        return ans;
    map<char, string> dict = {make_pair('1', "1"), make_pair('2', "abc"), make_pair('3', "def"),
                              make_pair('4', "ghi"), make_pair('5', "jkl"), make_pair('6', "mno"),
                              make_pair('7', "pqrs"), make_pair('8', "tuv"), make_pair('9', "wxyz"),
                              make_pair('*', "*+"), make_pair('0', "0"), make_pair('#', "#")};
    helper(digits, 0, dict, ans);
    return ans;
}

void Leetcode17::helper(string digits, int index,
                        map<char, string> &dict, vector<string> &ans) {
    if (index == digits.size()) {
        ans.push_back(digits);
        return;
    }
    string s = dict[digits[index]];
    for (int i = 0; i < s.length(); ++i) {
        digits[index] = s[i];
        helper(digits, index + 1, dict, ans);
    }
}

void Leetcode17::test17() {
    string digits = "234";
    vector<string> ans = letterCombinations(digits);
    for (auto item : ans) {
        cout << item << endl;
    }
}
