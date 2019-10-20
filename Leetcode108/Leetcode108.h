//
// Created by hans on 4/26/18.
//

#ifndef LEETCODE_LEETCODE108_H
#define LEETCODE_LEETCODE108_H

#include <config.h>

class Leetcode108 {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums);

    TreeNode *sortedArrayToBST2(vector<int> &nums);

    void test108();

private:
    TreeNode *helper(vector<int> &nuns, int low, int high);

};


#endif //LEETCODE_LEETCODE108_H
