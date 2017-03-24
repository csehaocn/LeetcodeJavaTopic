/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class Solution {
    
    public int depthSumAux(List<NestedInteger> nestedList, int initDepth){
        int size = nestedList.size();
        if(0 == size){
            return 0;
        }
        int ret = 0;
        for(int i = 0; i != size; ++i){
            NestedInteger c = nestedList.get(i);
            if(c.isInteger()){
                ret += initDepth * c.getInteger();
            }else{
                ret += depthSumAux(c.getList(), initDepth+1);
            }
        }
        
        return ret;
    }
    
    public int depthSum(List<NestedInteger> nestedList) {
        return depthSumAux(nestedList, 1);
    }
}
