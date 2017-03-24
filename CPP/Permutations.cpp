#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        
        int len = num.size();
        
        if(0 == len)
            return res;

        if(1 == len)
        {
            res.push_back(num);
        }
            
        for(int i =0; i != len; ++i)
        {
            // Swap it, man.
            swap(num[0],num[i]);
            vector<int> vt(num.begin()+1, num.end());
            vector<vector<int> > tmp = permute(vt);
            for(auto it = tmp.begin(); it!=tmp.end(); ++it)
            {
                it->push_back(num[0]);
            }
            res.insert(res.end(),tmp.begin(),tmp.end());
            // No, swap back.
            swap(num[0],num[i]);
        }

        return res;
        
    }
};

int main()
{
    return 0;
}
