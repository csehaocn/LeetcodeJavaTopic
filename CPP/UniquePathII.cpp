#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
    
    vector<vector<int> > dp;
    
    void DFS(vector<vector<int> > &obstacleGrid, const int &size_m, const int &size_n, int m, int n){
        // First mistake, mistake the obstacleGrid index and the problem size index. 
        //if( 1 == obstacleGrid[m][n]){
        
        if( 1 == obstacleGrid[size_m-m][size_n-n]){
            dp[m][n] = 0;
        }
        else if(1 == m && 1 == n){
            dp[m][n] = 1;
        }
        else{
            if(m > 1 && -1 == dp[m-1][n])
                DFS(obstacleGrid, size_m, size_n, m-1, n);
            if(n > 1 && -1 == dp[m][n-1])
                DFS(obstacleGrid, size_m, size_n, m, n-1);
            
            if(1 == m)
                dp[m][n] = dp[m][n-1];
            else if(1 == n)
                dp[m][n] = dp[m-1][n];
            else
                dp[m][n] = dp[m][n-1]+dp[m-1][n];
        }
        return;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        
        int m = obstacleGrid.size();
        
        if(0 == m)
            return 0;

        int n = obstacleGrid[0].size();

        
        dp = vector<vector<int> >();
        
        for(int i =0; i!=m+1; ++i)
            dp.push_back(vector<int>(n+1, -1));

        DFS(obstacleGrid, m, n, m, n);
        
        return dp[m][n];
    }
};

int main(){
    Solution S;
    vector<vector<int> > obstacleGrid;
    vector<int> tmp1 = {0, 0, 0};
    vector<int> tmp2 = {0, 1, 0};
    vector<int> tmp3 = {0, 0, 0};
    obstacleGrid.push_back(tmp1);
    obstacleGrid.push_back(tmp2);
    obstacleGrid.push_back(tmp3);
    cout << S.uniquePathsWithObstacles(obstacleGrid);

}
