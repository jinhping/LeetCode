//Solution 1
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
    int helper(TreeNode * root, int &res) {
        if (root == NULL) {
            return 0;
        }
        int left = helper(root -> left, res);
        int right = helper(root -> right, res);
        if (left < 0) {
            left = 0;
        }
        if (right < 0) {
            right = 0;
        }
        if (left + right + root -> val > res) {
            res = left + right + root -> val;
        }
        return root -> val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int max = INT_MIN; 
        helper(root, max);
        return max;
    }
};


//Solution 2
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int max_helper(TreeNode *root, int &maxSum) {
        if (root == NULL) {
            return 0;
        }
        int left = max(0,max_helper(root->left,maxSum));
        int right = max(0,max_helper(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return max(left, right) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        max_helper(root, maxSum);
        return maxSum;       
    }
};

//Follow up: if node is from root to any node
class Solution {
public:
    /**
     * @param root the root of binary tree.
     * @return an integer
     */
    int max_helper(TreeNode *root, int maxSum) {
        if (root == NULL) {
            return 0;
        }
        int left = max_helper(root->left,maxSum);
        int right = max_helper(root->right, maxSum);
        maxSum = max(0, max(left, right)) + root->val + maxSum;
        return maxSum;
    }
    int maxPathSum2(TreeNode *root) {
        int maxSum = 0;
        maxSum = max_helper(root, maxSum);
        return maxSum;   
    }
};