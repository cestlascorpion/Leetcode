//
// Created by cestl on 2018/5/3 0003.
//

#ifndef LEETCODE_LEETCODE637_H
#define LEETCODE_LEETCODE637_H

#include "../config.h"

class Leetcode637 {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> elem;
            double sum = 0.0;
            int width = q.size();
            for (int i = 0; i < width; i++) {
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                elem.push_back(q.front()->val);
                q.pop();
            }
            for (int i = 0; i < elem.size(); i++)
                sum += elem[i];
            ans.push_back(sum / elem.size());
        }
        return ans;
    }
};


#endif //LEETCODE_LEETCODE637_H
