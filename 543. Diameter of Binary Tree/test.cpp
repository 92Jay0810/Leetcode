#include <iostream>
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

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int res = 0;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode *root, int &res)
    {
        if (!root)
        {
            return 0;
        }
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        // 包含左右兩條路，因此相加 算答案
        res = std::max(res, left + right);
        // return 包含該點算最長的節點數
        return 1 + std::max(left, right);
    }
};
