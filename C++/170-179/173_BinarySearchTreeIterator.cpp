/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> s;
private: 
    void pushAll(TreeNode *node) {
        for (; node != NULL; node = node -> left) {
            s.push(node);
        }    
    }
    
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (s.empty()) {
            return false;
        } else {
            return true;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * top = s.top();
        s.pop();
        pushAll(top -> right);
        return top -> val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */