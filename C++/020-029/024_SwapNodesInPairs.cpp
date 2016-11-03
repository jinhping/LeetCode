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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode * dummy = new ListNode(0);
        dummy -> next = head;
        ListNode * cur = dummy;
        while (cur -> next != NULL && cur -> next -> next != NULL) {
            ListNode * first = cur -> next;
            ListNode * second = cur -> next -> next;
            first -> next = second -> next;
            cur -> next = second;
            second -> next = first;
            cur = cur -> next -> next;
        }
        return dummy -> next;
    }
};