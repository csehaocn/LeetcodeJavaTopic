/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

/*
Algorithm: Reservoir Sampling Algorithm
*/
public class Solution {

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode head;

    public Solution(ListNode head) {
        this.head = head;
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        if(null == head)
            return 0;
        
        int res = 0;
        ListNode c = head;
        int count = 1;
        while(null != c){
            if( Math.random()*count < 1 ){
                res = c.val;
            }
            ++count;
            c = c.next;
        }
        
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
