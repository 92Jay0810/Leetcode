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
    // 此方法用iteration ,底下有resursive
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || !p || !q)
        {
            return nullptr;
        }
        TreeNode *curr = root;
        while (curr)
        {
            // 因為binary search tree的特性， 最小的都大於curr 一定兩個都在右邊
            if (std::min(p->val, q->val) > curr->val)
            {
                curr = curr->right;
            }
            // 最大的都小於root 一定兩個都在左邊
            else if (std::max(p->val, q->val) < curr->val)
            {
                curr = curr->left;
            }
            // 不符合一定一左一右 回傳curr
            else
            {
                return curr;
            }
        }
        return nullptr;
    }
    /* resursive;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || !p || !q)
        {
            return nullptr;
        }
        // 因為binary search tree的特性， 最小的都大於root 一定兩個都在右邊
        if (std::min(p->val, q->val) > root->val)
        {
            return (lowestCommonAncestor(root->right, p, q));
        }
        // 最大的都小於root 一定兩個都在左邊
        else if (std::max(p->val, q->val) < root->val)
        {
            return (lowestCommonAncestor(root->left, p, q));
        }
        // 不符合一定一左一右 回傳root
        else
        {
            return root;
        }
    }*/
};
