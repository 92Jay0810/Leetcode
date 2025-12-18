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
// 自己寫出來 讚!
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        vector<int> result;
        queue<TreeNode *> cache;
        cache.push(root);
        while (!cache.empty())
        {
            // 直接拿 當層最右邊做解答
            TreeNode *visible = cache.back();
            result.push_back(visible->val);
            for (int i = cache.size(); i > 0; i--)
            {
                TreeNode *temp = cache.front();
                cache.pop();
                if (temp->left)
                    cache.push(temp->left);
                if (temp->right)
                    cache.push(temp->right);
            }
        }
        return result;
    }
};
