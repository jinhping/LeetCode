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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }
        ListNode * l1 = headA;
        ListNode * l2 = headB;
        while (l1 != NULL && l2 != NULL && l1 != l2) {
            l1 = l1 -> next;
            l2 = l2 -> next;
            if (l1 == l2) {
                return l2;
            }
            if (l1 == NULL) {
                l1 = headB;
            }
            if (l2 == NULL) {
                l2 = headA;
            }
        }
        return l1;
    }
};