
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
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        // long過測資
        return testIsValidBST(root, LONG_MIN, LONG_MAX);
    }
    // 不能只是比較當前節點的左右節點, 必須確保左branch所有節點小於root 右branch所有節點大於root
    bool testIsValidBST(TreeNode *root, long left_range, long right_range)
    {
        if (!root)
        {
            return true;
        }
        /* 這樣不行
        if (root->left && root->val <= root->left->val)
        {
            return false;
        }
        else if (root->right && root->val >= root->right->val)
        {
            return false;
        }*/
        if (root->val >= right_range)
        {
            return false;
        }
        if (root->val <= left_range)
        {
            return false;
        }
        return testIsValidBST(root->left, left_range, root->val) && testIsValidBST(root->right, root->val, right_range);
    }
};