#include <iostream>
#include <vector>
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
// 改用dfs去寫
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return dfs(root)[0];
    }
    std::vector<int> dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {1, 0};
        }
        std::vector<int> left = dfs(root->left);
        std::vector<int> right = dfs(root->right);
        int balance = (left[0] == 1) && (right[0] == 1) && (abs(left[1] - right[1]) <= 1);
        int height = 1 + std::max(left[1], right[1]);
        return {balance ? 1 : 0, height};
    }
};
/* 暴力法
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        int left = height(root->left);
        int right = height(root->right);
        if (std::abs(left - right) > 1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }
};*/
