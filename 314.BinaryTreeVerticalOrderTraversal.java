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
    
    
    public List<List<Integer>> verticalOrder(TreeNode root) {
        
        List<List<Integer>> ret = new ArrayList<>();
        
        if(null == root)
            return ret;
        
        List<List<Integer>> left = new ArrayList<>();
        List<List<Integer>> right = new ArrayList<>();
        List<Integer> center = new ArrayList<>();
        
        Queue<TreeNode> q = new LinkedList<>();
        Queue<Integer> qOff = new LinkedList<>();
        
        q.add(root);
        q.add(null);
        qOff.add(0);
        qOff.add(0);
        
        while(q.size() > 1){
            TreeNode t = q.poll();
            int offSet = qOff.poll();
            while(null != t){
                
                if(0 == offSet)
                    center.add(t.val);
                else{
                    List<List<Integer>> l = offSet < 0 ? left : right;
                    int off = offSet < 0 ? -1*offSet : offSet;
                    while(l.size() < off){
                        l.add(new ArrayList<Integer>());
                    }
                    l.get(off-1).add(t.val);
                }
                
                if(null != t.left){
                    q.add(t.left);
                    qOff.add(offSet -1);
                }
                if(null != t.right){
                    q.add(t.right);
                    qOff.add(offSet + 1);
                }
                
                t = q.poll();
                offSet = qOff.poll();
            }
            q.add(null);
            qOff.add(0);
        }
        
        for(int i = left.size()-1; i >= 0; --i){
            List<Integer> list = left.get(i);
            if(!list.isEmpty()){
                ret.add(list);
            }
        }
        
        ret.add(center);
        
        for(int i = 0; i < right.size(); ++i){
            List<Integer> list = right.get(i);
            if(!list.isEmpty()){
                ret.add(list);
            }
        }
        
        return ret;
    }
}
