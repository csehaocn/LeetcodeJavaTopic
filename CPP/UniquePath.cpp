class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int> > dp;
        
        for(int i =0; i!=m+1; ++i)
            dp.push_back(vector<int>(n+1));
            
        for(int i = 1; i !=m+1; ++i){
            dp[i][1] = 1;
        }
        
        for(int i = 1; i !=n+1; ++i){
            dp[1][i] = 1;
        }
        
        for(int k = 2; k!=min(m+1,n+1); ++k)
        {
            for(int j = k; j !=n+1; ++j){
                dp[k][j] = dp[k-1][j]+dp[k][j-1];
            }
            for(int i = k; i !=m+1; ++i){
                dp[i][k] = dp[i-1][k]+dp[i][k-1];
            }
        }
        
        return dp[m][n];
    }
};
