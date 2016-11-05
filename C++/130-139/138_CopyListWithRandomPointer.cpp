/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
       RandomListNode * newHead = head;
       if (head == NULL) {
           return newHead;
       }
       RandomListNode * l1;
       RandomListNode * l2;
       
       for (l1 = head; l1 != NULL; l1 = l1 -> next -> next) {
           l2 = new RandomListNode(l1 -> label);
           l2 -> next = l1 -> next;
           l1 -> next = l2;
       }
       
       for (l1 = head; l1 != NULL; l1 = l1 -> next -> next) {
           if (l1 -> random == NULL) {
               l1 -> next -> random = NULL;
           } else {
               l1 -> next -> random = l1 -> random -> next;
           }
       }
       
       l1 = head; 
       newHead = l1 -> next;
       while (l1 != NULL) {
           l2 = l1 -> next;
           l1 -> next = l2 -> next;
           l1 = l2 -> next;
           if (l2 -> next != NULL) {
               l2 -> next = l1 -> next;
           }
       }
       return newHead;
    }
};