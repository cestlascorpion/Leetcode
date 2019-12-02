//
// Created by hans on 18-4-23.
//

#ifndef LEETCODE_CONFIG_H
#define LEETCODE_CONFIG_H

#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x)
        : val(x)
        , next(nullptr) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    explicit TreeLinkNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
        , next(nullptr) {}
};


#endif // LEETCODE_CONFIG_H
