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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root == NULL) {
            return results;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> path;
            int size = q.size();
            while (size != 0) {
                TreeNode * front = q.front();
                if (front -> left != NULL) {
                    q.push(front -> left);
                }
                if (front -> right != NULL) {
                    q.push(front -> right);
                }
                q.pop();
                path.push_back(front -> val);
                size--;
            }
            results.push_back(path);
        }
        return results;
    }
};