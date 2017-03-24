public class Solution {
    public int[][] multiply(int[][] A, int[][] B) {
        // m p n
        int m = A.length;
        int p = A[0].length;
        int n = B[0].length;
        
        int[][] res = new int[m][n];
        
        if(0 == m || 0 == p || 0 == n)
            return res;
        
        for(int i = 0; i != m; ++i)
        for(int j = 0; j != p; ++j){
            // Comment this if statement, resulting in a 10 times more running time.
            if(0 != A[i][j]){
                for(int k = 0; k != n; ++k){
                    // Comment this if statment, resulting in a 1.5 times more running time.
                    if(0 != B[j][k]) 
                        res[i][k] += A[i][j]*B[j][k];
                }
            }            
        }
        
        return res;
    }
}
