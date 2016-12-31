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
    ListNode* oddEvenList(ListNode* head) {
        if(!head ||head->next == nullptr ) return head;
        ListNode * odd = head;
        ListNode * even_head = head -> next;
        ListNode * even = head -> next;
        while(even != nullptr && even->next != nullptr){
            odd -> next = even -> next;
            even -> next = odd -> next -> next;
            even = even -> next;
            odd = odd -> next;
        }
        odd -> next = even_head;
        return head;
    }
};