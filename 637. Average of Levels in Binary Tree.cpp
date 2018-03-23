struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> elem;
            double sum = 0.0;
            int width = q.size();
            for (int i = 0; i < width; i++)
            {
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
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