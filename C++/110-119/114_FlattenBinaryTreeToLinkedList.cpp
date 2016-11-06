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
    void helper (vector<TreeNode *> &results, TreeNode *root) {
        if (root == NULL) {
            return;
        }
        results.push_back(root);
        helper(results, root -> left);
        helper(results, root -> right);
    } 
    
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        } 
        vector<TreeNode*> results;
        helper(results, root);
        TreeNode * cur = new TreeNode(0);
        root = cur -> right;
        for (auto x : results) {
            cur -> right = x;
            cur -> right -> left = NULL;
            cur = cur -> right;
        }
    }
};