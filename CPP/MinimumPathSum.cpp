class Solution {
    
        
    vector<vector<int> > dp;
    
    void DFS(vector<vector<int> > &grid, const int &size_m, const int &size_n, int m, int n){

        if(1 == m && 1 == n){
            dp[m][n] = grid[size_m-m][size_n-n];
        }
        else{
            if(m > 1 && -1 == dp[m-1][n])
                DFS(grid, size_m, size_n, m-1, n);
            if(n > 1 && -1 == dp[m][n-1])
                DFS(grid, size_m, size_n, m, n-1);
            
            if(1 == m)
                dp[m][n] = dp[m][n-1]+grid[size_m-m][size_n-n];
            else if(1 == n)
                dp[m][n] = dp[m-1][n]+grid[size_m-m][size_n-n];
            else
                dp[m][n] = min(dp[m][n-1],dp[m-1][n])+grid[size_m-m][size_n-n];
        }
        return;
    }
    
public:
    int minPathSum(vector<vector<int> > &grid) {
        
        int m = grid.size();
        
        if(0 == m)
            return 0;

        int n = grid[0].size();

        
        dp = vector<vector<int> >();
        
        for(int i =0; i!=m+1; ++i)
            dp.push_back(vector<int>(n+1, -1));

        DFS(grid, m, n, m, n);
        
        return dp[m][n];
    }
};
