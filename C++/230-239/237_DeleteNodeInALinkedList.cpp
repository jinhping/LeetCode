//Solution 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //copy next ListNode onto this node
    //move next = next->next
    void deleteNode(ListNode* node) {
        if (node == NULL) {
            return;
        }
        ListNode *second = node -> next;
        node -> val = second -> val; 
        node -> next = second -> next;
        delete second;
    }
};


//Solution 2
class Solution {
public:
    void deleteNode(ListNode* node) {
        * node = * (node -> next);
    }
};