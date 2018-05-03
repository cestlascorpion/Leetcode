//
// Created by cestl on 2018/5/3 0003.
//

#include "Leetcode784.h"

vector<string> Leetcode784::letterCasePermutation(string S) {
    vector<string> ans;
    helper(ans, S, 0);
    return ans;
}

void Leetcode784::helper(vector<string> &ans, string S, int i) {
    if (i >= S.length()) {
        ans.push_back(S);
        return;
    }
    if (!(S[i] >= '0' && S[i] <= '9')) {
        S[i] = tolower(S[i]);
        helper(ans, S, i + 1);
        //深度优先遍历 所以会在该语句走到S最后，然后push_back
        S[i] = toupper(S[i]);
        helper(ans, S, i + 1);
        //第一个返回后，将修改的字母从小写改为大写，然后push_back
        //然后返回到倒数第二个字母的分岔路口，字母会重新修改，所以可以传递引用
    } else
        helper(ans, S, i + 1);
}
