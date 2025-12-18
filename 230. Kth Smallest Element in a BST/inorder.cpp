#include <iostream>
#include <vector>
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

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> result;
        addInVector(root, result);
        return result[k - 1];
    }

    void addInVector(TreeNode *node, vector<int> &all)
    {
        if (!node)
        {
            return;
        }
        addInVector(node->left, all);
        all.push_back(node->val);
        addInVector(node->right, all);
    }
};
