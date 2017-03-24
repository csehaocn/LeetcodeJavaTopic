#include "util.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    void DFS(vector<vector<int> > &res, vector<int> &comb, int n, int k, int start)
    {
        
        int currSize = comb.size();
        
        if( currSize == k ){
            res.push_back(comb);
            return ;
        }
            
        for(int i = start; i != n + 1 - (k - currSize) +1; ++i )
        {
            comb.push_back(i);
            DFS(res, comb, n, k, i+1);
            comb.pop_back();
        }
        
        return;
    }
    
public:
    vector<vector<int> > combine(int n, int k) {
            
            vector<vector<int> > res;
            
            vector<int> comb;

            DFS(res, comb, n, k, 1);    
            
            return res;
            
    }
};

int main()
{

    Solution S;
    vector<vector<int> > res = S.combine(4, 2);
    for(auto it = res.begin(); it != res.end(); it ++)
    {
        pVector(*it);
    }
    return 0;
}
