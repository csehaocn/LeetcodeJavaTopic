#include<vector>
#include<algorithm>
#include<cstdio>
#include<set>
#include"util.hpp"

using namespace std;

class Solution {
    
    vector<vector<int> > DFS(vector<int> &num){

        vector<vector<int> > res;
        
        int len = num.size();
        
        if(0 == len)
            return res;

        if(1 == len)
        {
            res.push_back(num);
        }

        set<int> si;

        for(int i =0; i != len; ++i)
        {

            // Swap it, man.
            if(si.find(num[i]) == si.end())
            {
                si.insert(num[i]);
                swap(num[0],num[i]);

                vector<int> vt(num.begin()+1, num.end());
                vector<vector<int> > tmp = DFS(vt);
                for(auto it = tmp.begin(); it!=tmp.end(); ++it)
                {
                    // NOTICE: There is a compilation error that you shold not modify the element of a set directly.
                    /*
                     * You should not edit the values stored in the set directly. I copied this from MSDN documentation which is somewhat authoritative:
                     *
                     * The STL container class set is used for the storage and retrieval of data from a collection in which the values of the elements contained are unique and serve as the key values according to which the data is automatically ordered. The value of an element in a set may not be changed directly. Instead, you must delete old values and insert elements with new values.
                     *
                     * Why this is is pretty easy to understand. The set implementation will have no way of knowing you have modified the value behind its back. The normal implementation is a red-black tree. Having changed the value, the position in the tree for that instance will be wrong. You would expect to see all manner of wrong behaviour, such as exists queries returning the wrong result on account of the search going down the wrong branch of the tree.
                     */
                    it->push_back(num[0]);
                }

                res.insert(res.end(), tmp.begin(),tmp.end());
                // No, swap back.
                swap(num[0],num[i]);
            }
        }

        return res;
    }

public:
    vector<vector<int> > permute(vector<int> &num) {
        
        vector<vector<int> > t = DFS(num);
        return vector<vector<int> >(t.begin(), t.end());

    }
};

int main()
{
    Solution sol;
    vector<int> p = {1,1,2};
    vector<vector<int> > ans = sol.permute(p);
    for(auto it = ans.begin(); it != ans.end(); ++it)
    {
        pVector(*it);
    }
    return 0;
}
