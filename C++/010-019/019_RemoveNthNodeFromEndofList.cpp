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
    //One pass solution: move the fast pointer n + 1 steps ahead and keep it n steps gap from the 
    // slow pointer. Then, move together.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * slow = head;
        ListNode * fast = head;
        while (n > 0) {
            fast = fast -> next;
            n--;
        }
        if (fast == NULL) {
            return head -> next;
        }
        fast = fast -> next;
        while (fast != NULL) {
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};