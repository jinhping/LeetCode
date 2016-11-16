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
    void helper(vector<string> &results, string path, TreeNode *root) {
        if (root -> left == NULL && root -> right == NULL) {
            results.push_back(path);
            return;
        }
        if (root -> left) {
            helper(results, path + "->" + to_string(root -> left -> val), root -> left);
        }
        if(root -> right){
            helper(results, path + "->" + to_string(root -> right -> val), root -> right);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        if (root == NULL) {
            return results;
        }
        string path = to_string(root -> val);
        helper(results, path, root);
        return results;
    }
};