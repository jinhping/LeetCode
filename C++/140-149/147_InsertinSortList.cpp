//Don't sort a linked list.
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode * cur = head;
        if (cur == NULL) {
            return head;
        }
        vector<int> values;
        while (cur != NULL) {
            values.push_back(cur -> val);
            cur = cur -> next;
        }
        sort(values.begin(), values.end());
        cur = head;
        int i = 0;
        while (cur != NULL) {
            cur -> val = values[i];
            i++;
            cur = cur -> next;
        }
        return head;
    }
};