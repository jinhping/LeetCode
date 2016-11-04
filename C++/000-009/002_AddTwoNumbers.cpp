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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * dummy = new ListNode(0);
        ListNode * cur = dummy;
        int carry = 0;
        
        while (l1 != NULL || l2 != NULL) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1 -> val;
            }
            if (l2 != NULL) {
                sum += l2 -> val;
            }
            sum += carry;
            ListNode * newNode = new ListNode(sum % 10);
            cur -> next = newNode;
            cur = cur -> next;
            sum = sum / 10;
            if (sum != 0) {
                carry = 1;
            } else {
                carry = 0;
            }
            if (l1 != NULL) {
                l1 = l1 -> next;
            }
            if (l2 != NULL) {
                l2 = l2 -> next;
            }
        }
        if (carry == 1) {
           ListNode * newNode = new ListNode(1);
           cur -> next = newNode;
        }
        return dummy -> next;
    }
};