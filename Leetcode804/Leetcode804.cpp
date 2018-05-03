//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode804.h"

int Leetcode804::uniqueMorseRepresentations(vector<string> &words) {
    vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                        "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
                        "--.."};
    unordered_set<string> s;
    for (auto word : words) {
        string code;
        for (auto c : word)
            code += d[c - 'a'];
        s.insert(code);
    }
    return s.size();
}
