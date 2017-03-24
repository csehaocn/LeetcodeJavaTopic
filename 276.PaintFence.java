public class Solution {
    public int numWays(int n, int k) {
        /*
        AB[A-Z]
        AA[B-Z]
        DP1 end with AA
        DP2 end with AB
        DP1[i] = DP2[i-1];
        Error: DP2[i] = DP1[i-1]*(k-1);
        DP2[i] = ( DP1[i-1] + DP2[i-1] )*(k-1);
        */
        
        if(0 == n)
            return 0;
        if(1 == n)
            return k;
        if(0 == k)
            return 0;
        if(1 == k){
            return n <= 2? k : 0;    
        }   
        
        int[] DP1 = new int[2];
        int[] DP2 = new int[2];
        
        DP1[2%2] = k;
        DP2[2%2] = k * (k-1);
        
        for(int i = 3; i <= n; ++i){
            DP1[i%2] = DP2[(i-1)%2];
            // Error: DP2[i%2] = DP1[(i-1)%2]*(k-1);
            // AB can come from both AA and BA
            // Error * k - 1 ......
            DP2[i%2] = ( DP1[(i-1)%2] + DP2[(i-1)%2] ) * (k-1);
        }
        
        return DP1[n%2] + DP2[n%2];
    }
}
