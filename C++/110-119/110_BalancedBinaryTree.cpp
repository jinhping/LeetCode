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
    int depth(TreeNode * root) {
        if (root == NULL) {
            return 0;
        }
        int left = depth(root -> left);
        int right = depth(root -> right);
        if (left > right) {
            return left + 1;
        } else {
            return right + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        int left = depth(root -> left);
        int right = depth(root -> right);
        if (abs(left - right) > 1) {
            return false;
        }
        return isBalanced(root -> left) && isBalanced(root -> right);
    }
};