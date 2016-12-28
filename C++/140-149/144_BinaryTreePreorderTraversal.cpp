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
    void preorder(vector<int> &results, TreeNode *root) {
        if (root == NULL) {
            return;
        }
        results.push_back(root -> val);
        preorder(results, root -> left);
        preorder(results, root -> right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> results;
        preorder(results, root);
        return results;
    }
};