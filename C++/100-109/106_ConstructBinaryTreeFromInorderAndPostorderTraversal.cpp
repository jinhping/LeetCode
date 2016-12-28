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
    TreeNode *buildTree_inorder_postorder_helper(vector<int> &inorder, vector<int> &postorder, int inorder_start, int inorder_end, int postorder_start, int postorder_end) {
        if (inorder_start > inorder_end) {
            return NULL;
        }
        TreeNode *node = new TreeNode(postorder[postorder_end]);
        int pos = -1;
        for (int i = inorder_start; i <= inorder_end; i++) {
            if (inorder[i] == node->val ){
                pos = i; 
                break;
            }
        }
        node->left = buildTree_inorder_postorder_helper(inorder, postorder,
            inorder_start, pos - 1, postorder_start, postorder_start + pos -inorder_start - 1);
        node->right = buildTree_inorder_postorder_helper(inorder, postorder,
            pos + 1, inorder_end, postorder_start + pos - inorder_start, postorder_end - 1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree_inorder_postorder_helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};