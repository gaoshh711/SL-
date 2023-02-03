// author: gaoshh1
// 2/3/2023
// pass
// 4ms 62.61%
// 10.5 MB 26.09%
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
#include <algorithm>
class Solution
{
public:
    int none_y;
    int left_y;
    int right_y;
    void calculateNode(TreeNode *root, int x, int flag)
    {
        if (root == nullptr)
        {
            return;
        }
        else
        {
            if (root->val == x)
            {
                calculateNode(root->left, x, 1);
                calculateNode(root->right, x, 2);
            }
            else
            {
                switch (flag)
                {
                case 0:
                    none_y++;
                    break;
                case 1:
                    left_y++;
                    break;
                case 2:
                    right_y++;
                    break;

                default:
                    break;
                }
                if (root->left != nullptr)
                {
                    calculateNode(root->left, x, flag);
                }
                if (root->right != nullptr)
                {
                    calculateNode(root->right, x, flag);
                }
            }
        }
    }
    bool btreeGameWinningMove(TreeNode *root, int n, int x)
    {
        none_y = 0;
        right_y = 0;
        left_y = 0;
        calculateNode(root, x, 0);
        int y_max = std::max(none_y, right_y);
        y_max = std::max(y_max, left_y);
        if (y_max >= (n + 1) / 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};