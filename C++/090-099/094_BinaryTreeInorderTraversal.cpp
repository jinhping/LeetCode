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
    void helper(TreeNode * root, vector<int> &results) {
        if (root == NULL) {
            return;
        }
        helper(root -> left, results);
        results.push_back(root -> val);
        helper(root -> right, results);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        helper(root, results);
        return results;
    }
};