
class Solution {
    
private:
    vector<int> DP;
    int numTreesHelper(int n){

        if(DP[n]!=-1)
            return DP[n];
            
        int total = 0;
        for(int i = 0; i != n; ++i){
            total += numTreesHelper(i)*numTreesHelper(n-i-1);
        }
        DP[n] = total;
        return total;
    }
public:
    int numTrees(int n) {
        if(0 == n)
        return 0;
        if(1 == n)
        return 1;
        DP = vector<int>(n+1, -1);
        DP[0] = 1;
        DP[1] = 1;
        DP[2] = 2;
        
        
        // there are i to the left
        return numTreesHelper(n);
    }
};
