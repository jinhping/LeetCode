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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        traverse(root, sum);
        return sum;
    }
    
    void traverse(TreeNode* root, int & sum) {
        if (root == nullptr) {
            return;
        }
        if (root -> left != nullptr) {
            if (root -> left -> left == nullptr && root -> left -> right == nullptr) {
                sum += root -> left -> val;
            }
            traverse(root -> left, sum);
        }
        if (root -> right != nullptr) {
            traverse(root -> right, sum);
        }
    }
};