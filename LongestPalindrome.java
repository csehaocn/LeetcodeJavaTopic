public class Solution {
    public String longestPalindrome(String s) {
        int len = s.length();
        
        StringBuilder sb = new StringBuilder();
        if(0 == len)
            return sb.toString();
            
        boolean[][] dp = new boolean[1001][1001];
        
        // forgot to initialize the condition to include d = 0, d = 1.

        int l = 0;
        int u = 1;
        
        for(int i = 0; i < len; ++i){
            dp[i][i+1] = true;
        }
        
        for(int i = 0; i < len-1; ++i){
            if(s.charAt(i) == s.charAt(i+1)){
                dp[i][i+2] = true;
                l = i;
                u = i+2;
                
            }
            else{
                dp[i][i+2] = false;
            }
        }
        
        for(int d = 3; d <= len; ++d){
            for(int i = 0; i<=len-d; ++i){
                if(s.charAt(i) == s.charAt(i+d-1)){
                    dp[i][i+d] = dp[i+1][i+d-1];
                    // forgot to judge the condition here.
                    if(dp[i][i+d] == true){
                        l = i;
                        u = i+d;
                    }
                }
                else{
                    dp[i][i+d] = false;
                }
            }
        }
        
        return s.substring(l, u);
        
    }
}
