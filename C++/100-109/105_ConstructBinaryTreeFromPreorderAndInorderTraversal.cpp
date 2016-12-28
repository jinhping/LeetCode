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
     TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preorder_start, int preorder_end, int inorder_start, int inorder_end) {
        if (preorder_start > preorder_end) {
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[preorder_start]);
        int pos = -1;
        int inorder_size = inorder.size();
        for (int i = 0; i < inorder_size; i++) {
            if (inorder[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left = build(preorder, inorder, preorder_start + 1, 
            preorder_start + pos - inorder_start, inorder_start, pos - 1);
        node->right = build(preorder, inorder, preorder_end - inorder_end + pos + 1, 
            preorder_end, pos + 1, inorder_end);
        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};