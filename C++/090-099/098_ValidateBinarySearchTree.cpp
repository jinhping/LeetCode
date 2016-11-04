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
    void inorder(vector<int> &res, TreeNode *root) {
        if (root == NULL) {
            return;
        }   
        inorder(res, root -> left);
        res.push_back(root -> val);
        inorder(res, root -> right);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(res, root);
        for (int i = 1; i < res.size(); i++) {
            if (res[i] <= res[i - 1]) {
                return false;
            }
        }
        return true;
    }
};