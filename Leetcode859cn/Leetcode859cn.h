//
// Created by Wang on 2019/12/12.
//

#ifndef LEETCODE_LEETCODE859CN_H
#define LEETCODE_LEETCODE859CN_H

#include <config.h>

class Leetcode859cn {
public:
    bool buddyStrings(string A, string B);

private:
    bool contain_duplicate(const string &S) {
        vector<int> dict(26, 0);
        for (const auto &ch : S) {
            if (dict[ch - 'a'] != 0)
                return true;
            ++dict[ch - 'a'];
        }
        return false;
    }
};

#endif // LEETCODE_LEETCODE859CN_H
