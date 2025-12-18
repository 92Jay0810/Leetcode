
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
// 自己寫的(和發想) 棒!
// neetcode解答 用queue+pair 做iteration
// 及dfs 做resursive node算max(有就1)之後左右丟下去算result加起來 回傳
class Solution
{
public:
    int goodNodes(TreeNode *root)
    {
        int result = 0;
        check_good_node(&result, root, root->val);
        return result;
    }
    void check_good_node(int *result, TreeNode *root, int max)
    {
        if (!root)
        {
            return;
        }
        if (root->val >= max)
        {
            *result += 1;
            max = root->val;
        }
        check_good_node(result, root->left, max);
        check_good_node(result, root->right, max);
    }
};
