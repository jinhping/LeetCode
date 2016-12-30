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
    ListNode * reverse(ListNode * head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode * newHead = NULL;
        while (head != NULL) {
            ListNode * tmp = head;
            head = head -> next;
            tmp -> next = newHead;
            newHead = tmp;
        }
        return newHead;
    }

    ListNode * findMid(ListNode * head) {
        ListNode * slow = head;
        ListNode * fast = head -> next;
        while (fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    
    void merge(ListNode * head, ListNode * tail) {
        ListNode * newHead = head;
        int index = 0;
        ListNode * dummy = new ListNode(0);
        while (newHead != NULL && tail != NULL) {
            if (index % 2 == 0) {
                dummy -> next = newHead;
                newHead = newHead -> next;
            } else {
                dummy -> next = tail;
                tail = tail -> next;
            }
            dummy = dummy -> next;
            index++;
        }
        if (newHead != NULL) {
            dummy -> next = newHead;
        } else {
            dummy -> next = tail;
        }
    }
    
    void reorderList(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return;
        }
        ListNode * mid = findMid(head);
        ListNode * tail = reverse(mid -> next);
        mid -> next = NULL;
        merge(head, tail);
    }
};