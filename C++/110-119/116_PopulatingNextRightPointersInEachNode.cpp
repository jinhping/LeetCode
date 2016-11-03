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
        if (root -> left == NULL) {
            return;
        }
        TreeLinkNode * pre = root;
        TreeLinkNode * cur = NULL;
        while (pre -> left != NULL) {
            cur = pre;
            while (cur) {
                cur -> left -> next = cur -> right;
                if (cur -> next != NULL) {
                    cur -> right -> next = cur -> next -> left;
                }
                cur = cur -> next;
            }
            pre = pre -> left;
        }
    }
};