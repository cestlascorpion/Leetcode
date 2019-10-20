//
// Created by hans on 4/27/18.
//

#ifndef LEETCODE_LEETCODE278_H
#define LEETCODE_LEETCODE278_H

#include <config.h>

class Leetcode278 {
public:
    Leetcode278() {
        for (int i = 0; i < 5; ++i)
            version.push_back(0);
        for (int i = 0; i < 7; ++i)
            version.push_back(1);
        cout << "build version log" << endl;
    }

    int firstBadVersion(int n);

    void test278();

private:
    bool isBadVersion(int v) {
        if (v < version.size())
            return version[v];
        else
            throw (" bad input!");
    }

    vector<int> version;
};


#endif //LEETCODE_LEETCODE278_H
