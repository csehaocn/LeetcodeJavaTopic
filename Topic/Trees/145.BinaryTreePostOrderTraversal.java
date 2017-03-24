/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    // The only difference trick is the root node needs to be kept till the end of the program
    // We might use a stack to keep all of them.
    // Yu's coding garden
    // http://yucoding.blogspot.com/2013/12/leetcode-question-binary-tree-postorder.html
    // 
    /*
    (1) Push the root node into the stack.
    (2) while the stack is not empty, do:
       if 
          the top node is a leaf node (no left&right children), pop it.
          or if the top node has been visited, pop it. (here we use a sign head to show the latest popped node, if the top node's child = the latest popped node, either left or right, it must has been visited.)
       else
          b. push the right child of the top node (if exists)
          c. push the left child of the top node (if exists)
    */
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res =new ArrayList<>();
        if(null == root)
            return res;
        
        TreeNode c = root;
        Stack<TreeNode> s = new Stack<>();
        
        /* Solution 1: reverse the result from a pre order, right, left traversal
        // Error: Note. it must be a right left traversal, then reverse.
        while( null != c || !s.isEmpty()){
            if(null == c){
                c = s.pop().left; 
            }else{
                res.add(c.val);
                s.push(c);
                c = c.right;
            }
        }
        
        Collections.reverse(res);
        return res;
        */
        
        /* Solution 2: Since the root node has to be visited twice, live in the stack twice. 
            It needs a mechanism to judge if it is visited.
            The last visted node. i.e. pre Node is good enough for such a judgement.
        
        
        TreeNode pre = null;
        // We can define pre as the last added node in the traversal sequence. 
        // for each treenode, if 
        //                  1. it has a null right
        //                  2. its right node is the last added node.
        // It is the next node to add in the sequence.
        
        while( null != c || !s.isEmpty()){
            if(null == c){
                TreeNode t = s.pop();
                if(null == t.right || pre == t.right){
                    // null right tree or just finished visiting its right subtree
                    res.add(t.val);
                    pre = t;
                }else{
                    s.push(t);
                    c = t.right;
                }
            
            }else{
                s.push(c);
                c = c.left;
            }
        }
        
        return res;
        */
        
        /* Solution 3: the reason it is too complicated, is because it is a combination of different conditions, hard to sumarize into one if statement, when we are not doing it smoothly.
        // Multiple levels of complications
        //  1. Null is not allowed for current pointer
        //  2. we need if statements for down to left, down to right, up from left, up from right, times situation when left null, right null, both null. 
        
        /* Solution 4:
            Let's push both left and right child to stack,
            use a last reference to judge the direction path comparing with the top of the stack.
            Inspired by : 
            https://github.com/tl3shi/leetcode-summary/blob/master/binary-tree/Binary-Tree-Postorder-Traversal.md
        */
        
        s.add(root);
        TreeNode last = null;
        
        while(!s.isEmpty()){
            c = s.peek();
            if( null == c.left && null == c.right || (null != last && (last == c.left || last == c.right) ) ){
                // c is visited
                last = s.pop();
                res.add(last.val);
            }else{
                // Error: should push right first.
                if(null != c.right){
                    s.push(c.right);
                }
                if(null != c.left){
                    s.push(c.left);  
                }
            }
        }
        
        return res;
        
        /* Solution 5: Morris Traversal: Requires reverse of a linked list.
        */
        
    }
}
