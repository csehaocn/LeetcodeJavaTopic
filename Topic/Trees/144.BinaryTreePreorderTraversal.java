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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        if(null == root)
            return res;
        
        /* Let's explore the possibility a little bit.
            1.  Normal edition: with pointer and stack
            2.  Stack Only Edition
            3.  Pointer non-null edition
        */
        
        /* 1.    Normal edition
        
        
        TreeNode c = root;
        Stack<TreeNode> s = new Stack<>();
        
        while(!s.isEmpty() || null != c){
            if(null == c){
                c = s.pop().right;
            }else{
                res.add(c.val);
                s.push(c);
                c = c.left;
            }
        }
        
        return res;
        */
        
        /* 2.   Stack Only Edition
            Stack here plays the role of path recording as well, 
            while the top of the stack serves the role of pointer. 
        
        
        Stack<TreeNode> s = new Stack<>();
        s.push(root);
        
        while(!s.isEmpty()){
            if(null == s.peek()){
                s.pop();
                if(s.isEmpty()){
                    return res;
                }else{
                    if(null == s.peek()){
                        // throw exeption. it is not a possible state.;
                    }
                    s.push(s.pop().right);
                }
            }else{
                res.add(s.peek().val);
                s.push(s.peek().left);
            }
        }
        
        return res;
        
        */
        
        /* 3.  Pointer non-null edition
            Note: Much more complicated than null pointer enabled version.
            // contains two nested while loops while no judgement is allowed at the first one.
        
        
        Stack<TreeNode> s = new Stack<>();
        TreeNode c = root;
        // Error: while(!s.isEmpty()) is not a valid judgement anymore.
        while(true){
            res.add(c.val);
            if(null == c.left){
                if(null == c.right){
                    //
                    while(!s.isEmpty() && null == s.peek().right){
                        s.pop();
                    }
                    if(s.isEmpty())
                        return res;
                    else
                        c = s.pop().right;
                }else{
                    c = c.right;    
                }
            }else{
                s.push(c);
                c = c.left;
            }
        }
        */
        
        /* 4. Push right children version
        
        
        Stack<TreeNode> s = new Stack<>();
        TreeNode c = root;
        while(null != c || !s.isEmpty()){
            if(null == c){
                c = s.pop();
            }else{
                res.add(c.val);
                if(null != c.right)
                    s.push(c.right);
                c = c.left;
            }
        }
        
        return res;
        */
        
        /* 5. Push right children non null version
        
        
        Stack<TreeNode> s = new Stack<>();
        TreeNode c = root;
        while(null != c){
            res.add(c.val);
            if(null == c.left && null == c.right){
                // OK, here is the time c will be assigned with null, 
                // when s is empty
                if(s.isEmpty())
                    c = null;
                else
                    c = s.pop();
            }else if(null == c.left){
                c = c.right;
            }else{
                if(null != c.right)
                    s.push(c.right);
                c = c.left;
            }
        }
        return res;
        */
        
        /* 6. Push right children non null version. version 2
            inspired by the following code in postOrder traversal
            
            public List<Integer> postorderTraversal(TreeNode node) {
	            LinkedList<Integer> result = new LinkedList<Integer>();
	            Stack<TreeNode> leftChildren = new Stack<TreeNode>();
	            while(node != null) {
		            result.addFirst(node.val);
	        	    if (node.left != null) {
			        leftChildren.push(node.left);
		            }
		            node = node.right;
	        	    if (node == null && !leftChildren.isEmpty()) {
			            node = leftChildren.pop();
		            }
	            }
            return result;
            }
            
        */
        
        // In this method, 
        // we push right branch first, 
        // then take a look at left branch.
        // The same non null convienience can be applied on inOrder traversal
        
        Stack<TreeNode> s = new Stack<>();
        TreeNode c = root;
        
        while(null != c){
            res.add(c.val);
            if(null != c.right)
                s.push(c.right);

            if(null == c.left){
                if(s.isEmpty())
                    c = null;
                else
                    c = s.pop();
            }else{
                c = c.left;
            }
        }
        
        return res;
    }
}
