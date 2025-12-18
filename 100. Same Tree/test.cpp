#include <iostream>
#include <stack>
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        std::stack<std::pair<TreeNode *, TreeNode *>> check;
        check.push({p, q});
        while (!check.empty())
        {
            std::pair<TreeNode *, TreeNode *> temp = check.top();
            check.pop();
            TreeNode *p1 = temp.first;
            TreeNode *p2 = temp.second;
            if (!p1 && !p2)
            {
                continue;
            }
            if (!p1 || !p2 || (p1->val != p2->val))
            {
                return false;
            }
            check.push({p1->left, p2->left});
            check.push({p1->right, p2->right});
        }
        return true;
    }
};
