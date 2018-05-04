//
// Created by cestl on 2018/5/4 0004.
//

#include "Leetcode297.h"

string Leetcode297::serialize(TreeNode *root) {
    if (root == nullptr)
        return "[]";
    string ans;
    ans += "[";
    serializeHelper(root, ans);
    ans[ans.size() - 1] = ']';
    return ans;
}

void Leetcode297::serializeHelper(TreeNode *root, string &ans) {
    if (root == nullptr) {
        ans += "#,";
        return;
    }
    ans += to_string(root->val);
    ans += ",";
    serializeHelper(root->left, ans);
    serializeHelper(root->right, ans);
}

TreeNode *Leetcode297::deserialize(string data) {
    if (data == "[]")
        return nullptr;
    list<string> str = deserializeSplit(data);
    return deserializeHelper(str);
}

list<string> Leetcode297::deserializeSplit(string &data) {
    list<string> str;
    int index = 1;
    //[1,2,#,#,3,4,6,#,#,#,5,#,#]
    while (index < data.size()) {
        int end = index;
        while (data[end] != ']' && data[end] != ',')
            ++end;
        str.push_back(data.substr(index, end - index));
        index = end + 1;
    }
    return str;
}

TreeNode *Leetcode297::deserializeHelper(list<string> &str) {
    if (str.empty())
        return nullptr;
    string s = str.front();
    str.pop_front();
    if (s == "#")
        return nullptr;
    TreeNode *root = new TreeNode(stoi(s));
    root->left = deserializeHelper(str);
    root->right = deserializeHelper(str);
    return root;
}

void Leetcode297::test297() {
    TreeNode p1(1);
    TreeNode p2(2);
    TreeNode p3(3);
    TreeNode p4(4);
    TreeNode p5(5);
    TreeNode p6(6);

    TreeNode *p = &p1;
    p1.left = &p2;
    p1.right = &p3;
    p3.left = &p4;
    p3.right = &p5;
    p4.left = &p6;

    string sans = serialize(p);
    cout << sans << endl;
    TreeNode *pans = deserialize(sans);
    string sans2 = serialize(pans);
    cout << sans2 << endl;
}



