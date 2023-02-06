// author: gaoshh1
// pass
// time: 12ms 73.11%
// capacity: 14.6mb 54.62%
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool calculate(TreeNode *root)
    {
        if (root->left == nullptr)
        {
            return root->val == 1 ? true : false;
        }
        else
        {
            return root->val == 2 ? (calculate(root->left) || calculate(root->right)) : (calculate(root->left) && calculate(root->right));
        }
    }
    bool evaluateTree(TreeNode *root)
    {
        return calculate(root);
    }
};