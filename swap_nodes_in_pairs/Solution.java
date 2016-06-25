
/* Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null){
            return head;
        }
        ListNode thisOne = head;
        ListNode nextOne = head.next;
        // swap
        thisOne.next = swapPairs(nextOne.next);
        nextOne.next = thisOne;
        head = nextOne;

        return head;
    }
}
