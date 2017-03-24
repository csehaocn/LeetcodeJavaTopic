/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    
    public boolean plusOneAux(ListNode head){
        
        if(null == head.next || plusOneAux(head.next) ){
            head.val += 1;
        }
        
        if(10 == head.val){
            head.val = 0;
            return true;
        }else{
            return false;
        }
        
    }
    
    public ListNode plusOne(ListNode head) {
        
        if(null == head)
            return null;
        
        if(plusOneAux(head)){
            ListNode preHead = new ListNode(1);
            preHead.next = head;
            return preHead;
        }else{
            return head;
        }
    }
}
