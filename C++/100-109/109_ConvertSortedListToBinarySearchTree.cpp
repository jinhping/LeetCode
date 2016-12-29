/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
private: 
    ListNode * current;
    
    int getSize(ListNode * head) {
        int size = 0;
        while (head != NULL) {
            size++;
            head = head -> next;
        }
        return size;
    }
    
    TreeNode * helper(int size) {
        if (size <= 0) return NULL;
        TreeNode * left = helper(size / 2);
        TreeNode * root = new TreeNode(current -> val);
        current = current -> next;
        TreeNode * right = helper(size - 1 - size / 2);
        root -> left = left;
        root -> right = right;
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size; 
        current = head;
        size = getSize(head);
        return helper(size);
    }
};