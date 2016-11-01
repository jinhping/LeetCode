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
    void helper(TreeNode *root, int sum, vector<vector<int>> &res, vector<int> &path) {
        if (root == NULL) {
            return;
        }
        if (root -> val == sum && root -> left == NULL && root -> right == NULL) {
            path.push_back(root -> val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root -> val);
        helper(root -> left, sum - root -> val, res, path);
        helper(root -> right, sum - root -> val, res, path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        helper(root, sum, res, path);
        return res;
    }
};