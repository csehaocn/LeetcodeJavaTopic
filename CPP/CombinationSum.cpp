// 1. The first problem here is the candidate is a reference, not even a constance reference, therefore, we need to make copy. 
#include<vector>
#include<iostream>
#include"util.hpp"
using namespace std;

class Solution {
public:
    // Notice the problem here, this is a reference.  
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {

        vector<vector<int> > res;
        
        int len = candidates.size();

        if(0 == len)
            return res;
            
        if( 1 == len ){
            
            if(candidates[0] == 0 && target == 0)
            {
                vector<int> tmp(1,0);
                res.push_back(tmp);
                return res;
            }
            else if(0 == target % candidates[0]){
                vector<int> tmp(target/candidates[0], candidates[0]);
                res.push_back(tmp);
                return res;
            }
        }
        
        // Have to make a copy, or the reference will pass the originate data.
        int last = candidates.back();
        vector<int> candidates_copy(candidates);
        candidates_copy.pop_back();
        
        int mult = 0;
        
        while(mult*last <= target)
        {
           vector<vector<int> > tmp = combinationSum(candidates_copy, target-mult*last);

           for(auto it = tmp.begin(); it != tmp.end(); ++it)
           {
               vector<int> tt(mult, last);
               it->insert(it->end(), tt.begin(), tt.end());
           }

           res.insert(res.end(),tmp.begin(), tmp.end());
           ++mult;

        }
        
        return res;
        
    }
};

int main()
{
    vector<int> candidates = {2,3};
    int target = 5;
    Solution S;
    vector<vector<int> > res = S.combinationSum(candidates, target);
    pVector(res[0]);
}
