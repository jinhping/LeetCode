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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode * pre = head;
        ListNode * cur = head -> next;
        ListNode * nextNode;
        pre -> next = NULL;
        while (cur != NULL) {
            nextNode = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = nextNode;
        }
        return pre;
    }
};