#include <iostream>
#include <vector>
#include <unordered_map>
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
// inorder 作為 順序 preorder作為tree的訪問方式
class Solution
{
    int preorder_index = 0;
    unordered_map<int, int> index;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        // 這邊錯在 忘記size -1
        return dfs(preorder, 0, preorder.size() - 1);
    }
    // 一定要用範圍去assign給binary search tree
    // ex 比root大在root右邊 但比root右邊還大 會在root的右邊的右邊 設定好範圍 才不會出錯
    TreeNode *dfs(vector<int> &preorder, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int root_value = preorder[preorder_index];
        preorder_index++;
        TreeNode *root = new TreeNode(root_value);
        int mid = index[root_value];
        root->left = dfs(preorder, left, mid - 1);
        root->right = dfs(preorder, mid + 1, right);
        return root;
    }
};
