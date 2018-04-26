//
// Created by hans on 4/26/18.
//

#include "Leetcode108.h"

TreeNode *Leetcode108::sortedArrayToBST(vector<int> &nums) {
    if (nums.empty())
        return nullptr;

    return helper(nums, 0, nums.size() - 1);
}

TreeNode *Leetcode108::helper(vector<int> &nums, int low, int high) {
    if (low > high)
        return nullptr;

    int mid = (low + high) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = helper(nums, low, mid - 1);
    root->right = helper(nums, mid + 1, high);
    return root;
}

void Leetcode108::test108() {
    vector<int> nums = {-10, - 3, 0, 5, 9};
    TreeNode *root = sortedArrayToBST2(nums);
}

TreeNode *Leetcode108::sortedArrayToBST2(vector<int> &nums) {
    if (nums.empty())
        return nullptr;
    int low = 0;
    int high = nums.size() - 1;
    int mid = (low + high) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    queue<TreeNode *> node;
    queue<pair<int, int>> bound;

    bound.push(make_pair(0, mid - 1));
    bound.push(make_pair(mid + 1, high));
    node.push(root);

    while (!bound.empty()) {
        pair<int, int> b1 = bound.front();
        bound.pop();
        pair<int, int> b2 = bound.front();
        bound.pop();
        TreeNode *p = node.front();
        node.pop();
        if (b1.first > b1.second)
            p->left = nullptr;
        else {
            mid = (b1.first + b1.second) / 2;
            p->left = new TreeNode(nums[mid]);
            bound.push(make_pair(b1.first, mid - 1));
            bound.push(make_pair(mid + 1, b1.second));
            node.push(p->left);
        }
        if (b2.first > b2.second)
            p->right = nullptr;
        else {
            mid = (b2.first + b2.second) / 2;
            p->right = new TreeNode(nums[mid]);
            bound.push(make_pair(b2.first, mid - 1));
            bound.push(make_pair(mid + 1, b2.second));
            node.push(p->right);
        }
    }
    return root;
}
