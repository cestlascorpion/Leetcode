#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <limits.h>
#include <set>
#include <numeric>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
