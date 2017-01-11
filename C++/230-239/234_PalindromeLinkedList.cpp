//Solution 1
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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode * cur = head;
        while(cur != nullptr){
            s.push(cur->val);
            cur = cur -> next;
        }
        bool flag = true;
        while(head!=nullptr){
            if(head->val== s.top()){
                s.pop();
                head = head -> next;
            }else{
                flag = false;
                break;
            }
        }
        return flag;
    }
};


//Solution 2
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
    ListNode * reverseLinkedList(ListNode * head) {
        ListNode * cur = head -> next;
        ListNode * pre = head;
        ListNode * post;
        head -> next = NULL;
        while (cur != NULL) {
            post = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = post;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head -> next == NULL) {
            return true;
        }
        ListNode * slow = head;
        ListNode * fast = head -> next;
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = reverseLinkedList(slow -> next);
        slow = slow -> next;
        while (slow != NULL) {
            if (head -> val != slow -> val) {
                return false;
            }
            head = head -> next;
            slow = slow -> next;
        }
        return true;
    }
};