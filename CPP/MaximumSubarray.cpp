#include<vector>
#include<algorithm>
#include<iostream>
#include"util.hpp"

using namespace std;
// Two dimensional DP is not going to work. Try one dimensional DP.
class Solution2 {
public:
    int maxSubArray(int A[], int n) {
        
        vector<vector<int> > dp;
        vector<vector<int> > sum_dp;
        for(int i = 0; i != n+1; ++i){
            dp.push_back(vector<int>(n+1));
            sum_dp.push_back(vector<int>(n+1));
        }
        
        for(int i = 0; i != n; ++i){
            dp[i][i+1] = A[i];
            sum_dp[i][i+1] = A[i];
        }
        
        for(int i = 2; i != n+1; ++i){
            
            for(int l = 0; l != n-i+1; ++l){
                //int mMax = dp[l][l+i-1]+A[l+i-1];
                sum_dp[l][l+i] = sum_dp[l][l+i-1]+A[l+i-1];
                int mMax = sum_dp[l][l+i];
                //int mMax = INT_MIN;
                for(int k = l+1; k != l+i; ++k){
                    mMax = max(mMax, dp[l][k]);
                    mMax = max(mMax, dp[k][l+i]);
                }
                dp[l][l+i] = mMax;
            }
        }
        
        return dp[0][n];
    }
};


class Solution {
public:
    int maxSubArray(int A[], int n) {
        
        if(0 == n)
            return 0;
            
        vector<int> dp(n);

        dp[0] = A[0];

        
        for(int i = 1; i != n; ++i)
        {
            if(dp[i-1]+A[i] >= 0){
                dp[i] = max(A[i], dp[i-1]+A[i]);
            }
            else
            {
                dp[i] = A[i];
            }
        }
        
        pVector(dp);
        return *max_element(dp.begin(), dp.end());
    }
};

int main(){
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution S;
    cout << S.maxSubArray(A, 9);
}
