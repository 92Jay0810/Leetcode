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
// optimal
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> result(2);
        result[0] = k;
        dfs(root, result);
        return result[1];
    }

    void dfs(TreeNode *node, vector<int> &result)
    {
        if (!node)
        {
            return;
        }
        // 也是類似inorder去減1
        dfs(node->left, result);
        result[0]--;
        if (result[0] == 0)
        {
            result[1] = node->val;
            return;
        }
        dfs(node->right, result);
    }
};
