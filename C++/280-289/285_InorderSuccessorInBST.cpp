//Best Solution
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
    //Simply find the one just larger than p's value; 
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) {
            return NULL;
        }
        TreeNode * succ = NULL;
        while (root != NULL) {
            if (root -> val <= p -> val) {
                root = root -> right;
            } else {
                succ = root;
                root = root -> left;
            }
        }
        return succ;
    }
};


//Good one
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
    TreeNode* leftMost(TreeNode* node) {
        while (node -> left) node = node -> left;
        return node;
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p -> right) return leftMost(p -> right); 
        TreeNode* suc = NULL;
        while (root) {
            if (p -> val < root -> val) {
                suc = root;
                root = root -> left;
            }
            else if (p -> val > root -> val)
                root = root -> right; 
            else break;
        }
        return suc;
    }
};


//Naive Solution: 
class Solution {
public:
    void inorderSuccessor_helper(TreeNode *root, vector<TreeNode*> &container) {
        if (root == NULL) {
            return;
        }
        inorderSuccessor_helper(root->left, container);
        container.push_back(root);
        inorderSuccessor_helper(root->right, container);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> container;
        inorderSuccessor_helper(root, container);
        for (unsigned long i = 0; i < container.size(); i++) {
            if (container[i] == p && i != container.size() - 1) {
                return container[i+1];
            } 
        }
        return NULL;
    }
};