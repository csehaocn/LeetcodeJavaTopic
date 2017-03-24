public class Solution {
        
    public boolean verifyPreorder(int[] preorder) {
        // So the property of a BST has many ways to interpret, the property we are going to use here is, once the value is greater than its root, it is always going to be greater than its root.
        
        int len = preorder.length;
        if(0 == len)
            return true;
        
        Stack<Integer> st = new Stack<Integer>();
        st.push(preorder[0]);
        
        Integer lastPopped = null;
        
        for(int i = 1; i < len; ++i){
            int c = preorder[i];
            if(null != lastPopped && c < lastPopped)
                return false;
            while(!st.empty() && c > st.peek()){
                lastPopped = st.pop();
            }
            st.push(c);
        }
        
        // Error: return st.size() == 1, there are BSTs without the right sub branches.
        return true;
    }
    
    /* OK, this is not a 2D dp problem
    public int verifyPreorderAux(int[] preorder, int i, int j, int[][] dpRes, int[][] dpMin, int[][] dpMax){
        
        if(0 != dpRes[i][j]){
            return dpRes[i][j];
        }
        
        
        if(i == j-1){
            dpMin[i][j] = preorder[i];
            dpMax[i][j] = preorder[i];
            dpRes[i][j] = 1;
        }else if(i >= j){
            return 1;
        }else{
            dpRes[i][j] = -1;
            
            int m = preorder[i];
            int res = verifyPreorderAux(preorder, i+1, j, dpRes, dpMin, dpMax);
            if(1 == res && (m < dpMin[i+1][j] || m > dpMax[i+1][j]) ){
                dpMin[i][j] = Math.min(m, dpMin[i+1][j]);
                dpMax[i][j] = Math.max(m, dpMax[i+1][j]);
                dpRes[i][j] = 1;
                //System.out.println("i = " + i + "j = " + j);
            }else{
                for(int k = i+2; k < j; ++k){
                    int l = verifyPreorderAux(preorder, i+1, k, dpRes, dpMin, dpMax);
                    if(1 != l)
                        continue;
                    int r = verifyPreorderAux(preorder, k, j, dpRes, dpMin, dpMax);
                    if(1 == l && 1 == r && m < dpMin[k][j] && m > dpMax[i+1][k]){
                        dpRes[i][j] = 1;
                        dpMin[i][j] = dpMin[i+1][k];
                        dpMax[i][j] = dpMax[k][j];
                        break;
                    }
                } 
            }
        }
        
        return dpRes[i][j];
        
    }
    
    public boolean verifyPreorder(int[] preorder) {
        int len = preorder.length;
        if(len <= 2)
            return true;
        
        int[][] dpRes = new int[len+1][len+1];
        int[][] dpMin = new int[len+1][len+1];
        int[][] dpMax = new int[len+1][len+1];
        
        int res = verifyPreorderAux(preorder, 0, len, dpRes, dpMin, dpMax);
        
        return res == 1;
    }
    */
    
    /* Memory limit exceeded
    class retObj{
        int minVal;
        int maxVal;
        boolean isValid;
        public retObj(int min, int max, boolean v){
            minVal = min;
            maxVal = max;
            isValid = v;
        }
    }
    
    public retObj verifyPreorderAux(int[] preorder, retObj[][] dp, int i, int j){
        
        //System.out.println("i = " + i + "j = " + j);
        
        if(null != dp[i][j])
            return dp[i][j];
        else{
            if(i == j-1)
                dp[i][j] = new retObj(preorder[i], preorder[i], true);
            else if(i > j - 1)
                dp[i][j] = new retObj(0, 0, true);
            else{
                retObj n = verifyPreorderAux(preorder, dp, i+1, j);
                if(n.isValid && (n.minVal > preorder[i] || n.maxVal < preorder[i] )){
                    // Error: has to return a new obj instead of n.
                    dp[i][j] = new retObj(Math.min(n.minVal, preorder[i]), Math.max(n.maxVal, preorder[i]), true);
                    //System.out.println(dp[i][j].minVal + " " + dp[i][j].maxVal);
                    return dp[i][j];
                }
                
                
                // Error: forgot about empty subtree
                // for(int k = i+2; k < j; ++k){
                
                for(int k = i+2; k < j; ++k){
                    retObj l = verifyPreorderAux(preorder, dp, i+1, k);
                    retObj r = verifyPreorderAux(preorder, dp, k, j);
                    // OK, maxVal and minVal does not work on null trees, when I return with 0, 0 max and min value.
                    if(l.isValid && r.isValid && l.maxVal < preorder[i] && preorder[i] < r.minVal){
                        dp[i][j] = new retObj(l.minVal, r.maxVal, true);
                        //System.out.println("k = " + k);
                        break;
                    }
                }
                
                if(null == dp[i][j]){
                    dp[i][j] = new retObj(0, 0, false);
                }
            }
        }
        
        return dp[i][j];
    }
    
    public boolean verifyPreorder(int[] preorder) {
        // 2D dp
        int len = preorder.length;
        if(0 == len)
            return true;
        
        retObj[][] dp = new retObj[len+1][len+1];
        
        retObj r = verifyPreorderAux(preorder, dp, 0, len);
        return r.isValid;
    }
    */
}
