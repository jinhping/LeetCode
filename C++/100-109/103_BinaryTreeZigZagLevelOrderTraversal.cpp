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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if (root == NULL) {
            return results;
        }
        queue<TreeNode*> q;
        q.push(root);
        int odd = 1;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            while (size != 0) {
                level.push_back(q.front()->val);
                if (q.front()->left != NULL) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != NULL) {
                    q.push(q.front()->right);
                }
                q.pop();
                size--;
            }
            if (odd%2 == 1) {
                results.push_back(level);
                odd++;
            } else {
                reverse(level.begin(), level.end());
                results.push_back(level);
                odd++;
            }
        }
        return results;
    }
};