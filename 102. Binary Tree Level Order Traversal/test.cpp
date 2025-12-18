#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 自己寫出來 讚!  之後有優化
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        vector<vector<int>> result;
        queue<TreeNode *> cache;
        cache.push(root);
        while (!cache.empty())
        {
            vector<int> levelresult;
            for (int i = cache.size(); i > 0; i--)
            {
                TreeNode *temp = cache.front();
                levelresult.push_back(temp->val);
                cache.pop();
                if (temp->left)
                    cache.push(temp->left);
                if (temp->right)
                    cache.push(temp->right);
            }
            result.push_back(levelresult);
        }
        return result;
    }
};
