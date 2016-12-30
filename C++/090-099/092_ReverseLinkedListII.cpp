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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n || head == NULL) {
            return head;
        }
        ListNode * dummy = new ListNode(0);
        dummy -> next = head;
        head = dummy;
        
        //find the starting position
        for (int i = 1; i < m; i++) {
            if (head == NULL) {
                return NULL;
            }
            head = head -> next;
        }
        
        //rotate
        ListNode * preM = head;
        ListNode * nodeM = head -> next;
        ListNode * nodeN = nodeM;
        ListNode * postN = nodeM -> next;
        for (int i = m; i < n; i++) {
            if (postN == NULL) {
                return NULL;
            }
            ListNode * tmp = postN -> next;
            postN -> next = nodeN;
            nodeN = postN;
            postN = tmp;
        }
        nodeM -> next = postN;
        preM -> next = nodeN;
        return dummy -> next;
    }
};