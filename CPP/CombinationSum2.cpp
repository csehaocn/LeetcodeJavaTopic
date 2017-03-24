#include<vector>
#include<iostream>
#include"util.hpp"
using namespace std;

class Solution {
public:
    // Notice the problem here, this is a reference.  
    void DFS(vector<int> &candidates, int target, vector<int> &curr, set<vector<int> > &res, int level){

        int len = candidates.size();
        
        if (target < 0)
            return ;

        if( len - 1 == level ){
            
            if(target == 0)
            {
                vector<int> tmp = curr;
                sort(tmp.begin(), tmp.end());
                res.insert(tmp); 
                return;
            }
            else if(target == candidates[level])
            {
                curr.push_back(target);
                vector<int> tmp = curr;
                sort(tmp.begin(), tmp.end());
                res.insert(tmp);
                curr.pop_back();
                return; 
            }
            
            return ;
        }
        
        int last = candidates[level];

        DFS(candidates, target, curr, res, level+1);
        curr.push_back(last);
        DFS(candidates, target-last, curr, res, level+1);
        curr.pop_back();

        return;
        
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {

        set<vector<int> > res;
        vector<int> curr;

        DFS(candidates, target, curr, res, 0);

        return vector<vector<int> >(res.begin(),res.end());

    }
};

int main()
{
    vector<int> candidates = {2,3};
    int target = 5;
    Solution S;
    vector<vector<int> > res = S.combinationSum2(candidates, target);
    pVector(res[0]);
}
