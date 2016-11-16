/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode * root, int &res) {
        if (root == NULL) {
            return 0;
        }
        int left = helper(root -> left, res);
        int right = helper(root -> right, res);
        if (left < 0) {
            left = 0;
        }
        if (right < 0) {
            right = 0;
        }
        if (left + right + root -> val > res) {
            res = left + right + root -> val;
        }
        return root -> val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int max = INT_MIN; 
        helper(root, max);
        return max;
    }
};