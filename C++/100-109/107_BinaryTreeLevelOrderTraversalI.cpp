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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        stack<vector<int>> s;
        if(root == NULL) return result;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int size = q.size();
            while(size != 0){
                if(q.front()-> left != NULL){
                    q.push(q.front()->left);
                }
                if(q.front() -> right != NULL){
                     q.push(q.front()->right);
                }
                tmp.push_back(q.front() -> val);
                q.pop();
                size --;
            }
            s.push(tmp);
        }
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result; 
    }
};