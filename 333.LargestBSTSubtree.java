/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

    
    // 常见错误
    // 1.   BST的元素是不能相等的 root.val > rRet.get(0)
    // 2.   用list取代RetObj是完全可行的

public class Solution {
    
    class RetObj{
        
        int mMax;
        int mMin;
        int mCount;
        boolean mIsBST;
        
        public RetObj(int max, int min, int count, boolean isBST){
            mMax = max;
            mMin = min;
            mCount = count;
            mIsBST = isBST;
        }
        
    }
    
    public RetObj largestBSTSubtreeAux(TreeNode root){
        // root != null
        int max = root.val;
        int min = root.val;
        int maxCount = 1;
        int totalCount = 1;
        boolean isBST = true;
        
        if(null != root.left){
            RetObj l = largestBSTSubtreeAux(root.left);
            if(l.mIsBST && l.mMax < root.val){
                ;
            }else{
                isBST = false;
            }
            
            min = l.mMin;
            maxCount = Math.max(maxCount, l.mCount);
            totalCount += l.mCount;
        }
        
        if(null != root.right){
            RetObj r = largestBSTSubtreeAux(root.right);
            if(r.mIsBST && r.mMin > root.val){
                ;
            }else{
                isBST = false;
            }
            
            max = r.mMax;
            maxCount = Math.max(maxCount, r.mCount);
            totalCount += r.mCount;
        }
        
        return new RetObj(max, min, isBST?totalCount:maxCount, isBST);
        
    }
    
    public int largestBSTSubtree(TreeNode root) {
        if(null == root)
            return 0;
            
        RetObj ret = largestBSTSubtreeAux(root);
        return ret.mCount;
        
    }
}

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

    
    private List<Integer> largestBSTSubtreeAux(TreeNode root, List<Integer> res){
        // assert root != null
        int min = root.val;
        int max = root.val;
        int size = 1;
        
        if(null != root.left){
            List<Integer> lRet = largestBSTSubtreeAux(root.left, res);
            if( -1 == lRet.get(2) || root.val <= lRet.get(1) ){
                size = -1;
            }else{
                size += lRet.get(2);
            }
            min = lRet.get(0);
        }
        
        if(null != root.right){
            List<Integer> rRet = largestBSTSubtreeAux(root.right, res);
            if(-1 == size || -1 == rRet.get(2) || root.val >= rRet.get(0) ){
                size = -1;
            }else{
                size += rRet.get(2);
            }
            max = rRet.get(1);
        }

        
        res.set(0, Math.max(size, res.get(0)));
        
        return Arrays.asList(min, max, size);
    }
    
    public int largestBSTSubtree(TreeNode root) {
        
        ArrayList<Integer> res = new ArrayList<>(1);
        res.add(0);
        
        if(null == root)
            return 0;
        
        largestBSTSubtreeAux(root, res);
        
        return res.get(0);
        
    }
}
