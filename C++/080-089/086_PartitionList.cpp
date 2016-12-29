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
    ListNode* partition(ListNode* head, int x) {
        ListNode * dummy1 = new ListNode(0);
        ListNode * dummy2 = new ListNode(0);
        ListNode * dummyHead1 = dummy1;
        ListNode * dummyHead2 = dummy2;
        ListNode * cur = head;
        while (cur != NULL) {
            if (cur -> val < x) {
                dummy1 -> next = new ListNode(cur -> val);
                dummy1 = dummy1 -> next;
            } else {
                dummy2 -> next = new ListNode(cur -> val);
                dummy2 = dummy2 -> next;
            }
            cur = cur -> next;
        }
        dummy1 -> next = dummyHead2 -> next;
        dummy2 -> next = NULL;
        return dummyHead1 -> next;
    }
};