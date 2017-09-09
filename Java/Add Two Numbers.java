/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;
        int carry = 0;
        while (l1 != null || l2 != null) {
            if (l1 != null && l2 != null) {
                int sum = l1.val + l2.val + carry;
                int val = sum % 10;
                carry = sum / 10;
                cur.next = new ListNode(val);
                cur = cur.next;
                l1 = l1.next;
                l2 = l2.next;
            } else if (l1 != null) {
                int sum = l1.val + carry;
                int val = sum % 10;
                carry = sum / 10;
                cur.next = new ListNode(val);
                cur = cur.next;        
                l1 = l1.next;
            } else if (l2 != null) {
                int sum = l2.val + carry;
                int val = sum % 10;
                carry = sum / 10;
                cur.next = new ListNode(val);
                cur = cur.next;   
                l2 = l2.next;
            }
        }
        if (carry == 1) {
            cur.next = new ListNode(1);
        }
        return dummy.next;
    }
}