/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class Solution {
    
    
    // Seems this one pass solution is even slower than 2 pass solution? lol.
    
    // We actually don't need count in this data structure, sum is the one needed.
    private class DepthSumCount{
        
        int depth;
        // sum of all integers, no weights
        int sum;
        //int count;
        // weighted sum, the result
        int wSum;
        
        public DepthSumCount(int d, int s, int w){
            depth = d;
            sum = s;
            //count = c;
            wSum = w;
        }
    }
    
    private DepthSumCount MergeDSC(DepthSumCount prev, DepthSumCount next){
        if(next.depth == prev.depth){
            prev.sum += next.sum;
            //prev.count += next.count;
            prev.wSum += next.wSum;
            return prev;
        }else if(next.depth < prev.depth){
            // depth promotion of the next obj
            prev.sum += next.sum;
            prev.wSum += next.wSum + (prev.depth - next.depth) * next.sum;
            //prev.count += next.count;
            return prev;
        }else{
            next.sum += prev.sum;
            next.wSum += prev.wSum + (next.depth - prev.depth) * prev.sum;
            //next.count += prev.count;
            return next;
        }
    }
    
    public DepthSumCount depthSumInverseAux(List<NestedInteger> nestedList){
        
        // toTest
        if(nestedList.isEmpty()){
            return new DepthSumCount(0, 0, 0);
        }
        
        DepthSumCount dscObj = new DepthSumCount(0, 0, 0);
        
        boolean first = true;
        
        int len = nestedList.size();
        
        for(NestedInteger ni : nestedList){
            
            if(ni.isInteger()){
                dscObj = MergeDSC(dscObj, new DepthSumCount(1, ni.getInteger(), ni.getInteger()));
            }else{
                dscObj = MergeDSC(dscObj, depthSumInverseAux(ni.getList()));
            }
            
            //System.out.println(dscObj.depth + " " + dscObj.sum + " " + dscObj.count);
        }
        
        // Error: didn't increase the depth, we can either increase depth here or when the obj returns, carries different semantics.
        dscObj.depth++;
        
        return dscObj;
    }
    
    public int depthSumInverse(List<NestedInteger> nestedList) {
        return depthSumInverseAux(nestedList).wSum;
    }
}
