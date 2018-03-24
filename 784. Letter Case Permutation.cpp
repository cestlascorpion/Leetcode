#include "0.config.h"

class Solution
{
  public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> ans;
        dfs(ans, S, 0);
        return ans;
    }
    void dfs(vector<string> &ans, string S, int i)
    {
        if (i >= S.length())
        {
            ans.push_back(S);
            return;
        }
        if (!(S[i] >= '0' && S[i] <= '9'))
        {
            S[i] = tolower(S[i]);
            dfs(ans, S, i + 1);
            //深度优先遍历 所以会在该语句走到S最后，然后push_back
            S[i] = toupper(S[i]);
            dfs(ans, S, i + 1);
            //第一个返回后，将修改的字母从小写改为大写，然后push_back
            //然后返回到倒数第二个字母的分岔路口，字母会重新修改，所以可以传递引用
        }
        else
            dfs(ans, S, i + 1);
    }
};