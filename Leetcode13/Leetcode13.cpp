//
// Created by hans on 4/27/18.
//

#include "Leetcode13.h"

int Leetcode13::romanToInt(std::string s) {
    vector<char> ch = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector<int> nums = {1, 5, 10, 50, 100, 500, 1000};
    map<char, int> roman_map;
    for (int i = 0; i < ch.size(); ++i) {
        roman_map[ch[i]] = nums[i];
    }

    int ans = 0;
    for (int i = 0; i < s.length() - 1; ++i) {
        if (roman_map[s[i]] >= roman_map[s[i + 1]]) {
            ans += roman_map[s[i]];
        } else {
            ans -= roman_map[s[i]];
        }
    }
    ans += roman_map[s[s.length() - 1]];
    return ans;
}

void Leetcode13::test13() {
    vector<string> str{"IX", "LVIII", "MCMXCIV"};
    for (auto item :str) {
        cout << item << " " << romanToInt(item) << endl;
    }
    cout << endl;
}
