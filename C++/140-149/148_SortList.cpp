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
   ListNode *findmid(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode * sortList_merge(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while (left != NULL && right != NULL) {
            if (left -> val < right -> val) {
                tail -> next = left;
                tail = tail -> next;
                left = left -> next;
            } else {
                tail -> next = right;
                tail = tail -> next;
                right = right -> next;
            }
        }
        if (left != NULL) {
            tail -> next = left;
        } else {
            tail -> next = right;
        }
        return dummy->next;
    }
    
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode *mid = findmid(head);
        ListNode *right = sortList(mid -> next);
        mid -> next = NULL;
        ListNode *left = sortList(head);
        return sortList_merge(left, right);
    }
};