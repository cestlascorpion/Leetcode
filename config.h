//
// Created by hans on 18-4-23.
//

#ifndef LEETCODE_CONFIG_H
#define LEETCODE_CONFIG_H

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <utility>
#include <numeric>
#include <memory>
#include <regex>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};


struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    explicit TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

#endif //LEETCODE_CONFIG_H
