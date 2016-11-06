/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<TreeLinkNode*> v;
            while (!q.empty()) {
                v.push_back(q.front());
                q.pop();
            }
            if (v.size() == 1) {
                if (v[0] -> left != NULL) {
                    q.push(v[0] -> left);
                }
                if (v[0] -> right != NULL) {
                    q.push(v[0] -> right);
                }
            } else {
                for (int i = 0; i < v.size() - 1; i++) {
                    v[i] -> next = v[i + 1];
                    if (v[i] -> left != NULL) {
                        q.push(v[i] -> left);
                    }
                    if (v[i] -> right != NULL) {
                        q.push(v[i] -> right);
                    }
                }
                if (v[v.size() - 1] -> left != NULL) {
                    q.push(v[v.size() - 1] -> left);
                } 
                if (v[v.size() - 1] -> right != NULL) {
                    q.push(v[v.size() - 1] -> right);
                } 
            }
        }
        return;
    }
};