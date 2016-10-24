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
    void helper(TreeNode *root, double target,double &closest) {
        if (root == NULL) {
            return;
        }
        double diff_tmp = abs(root -> val - target);
        double diff2 = abs(closest - target);
        
        if (diff_tmp < diff2) {
            closest = root -> val;
        } 
        if (root -> val <= target) {
            helper(root -> right, target, closest);
        } else {
            helper(root -> left, target,  closest);

        }
    }

    int closestValue(TreeNode* root, double target) {
        double closest = root -> val;
        helper(root, target, closest);
        return closest;
    }
};