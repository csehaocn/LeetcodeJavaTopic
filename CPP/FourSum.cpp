#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include "util.hpp"

using namespace std;

class Solution {

    public:

        vector<vector<int> > fourSum(vector<int> &num, int target) {

            multimap<int, pair<int, int> > mymultimap;    

            set< vector<int> > res;

            int len = num.size();

            vector<vector<int> > rr;

            if(0 == len)
                return rr; 

            for(int i = 0; i!=len; ++i)
                for(int j=i+1; j!=len; ++j)
                {
                    mymultimap.insert(make_pair(num[i]+num[j], make_pair(i,j)));
                }

            for(auto it = mymultimap.begin(); it!= mymultimap.end(); ++it)
            {
                int val = it->first;   
                int t_val = target - val;
                if(mymultimap.find(t_val) != mymultimap.end())
                {
                    auto itlow = mymultimap.lower_bound (t_val);  // itlow points to b
                    auto itup = mymultimap.upper_bound (t_val);   // itup points to e (not d)
                    // print range [itlow,itup):
                    for (auto it2 = itlow; it2 != itup; ++it2)
                    {
                        int a1 = it->second.first;
                        int a2 = it->second.second;
                        int b1 = it2->second.first;
                        int b2 = it2->second.second;
                        if(a1 != b1 && a1 != b2 && a2 != b1 && a2 != b2)
                        {
                            vector<int> temp;
                            temp.push_back(num[a1]);
                            temp.push_back(num[a2]);
                            temp.push_back(num[b1]);
                            temp.push_back(num[b2]);
                            sort(temp.begin(), temp.end());
                            res.insert(temp);
                        }

                    }
                }
            }

            vector<vector<int> > result(res.begin(), res.end());

            return result;
        }
};

#include <iostream>
#include <map>

int main ()
{
  Solution S;

  vector<int> sum = {1, -1, 0, 0, 4, 3};

  vector<vector<int> > t = S.fourSum(sum, 0);

  for(auto it = t.begin(); it != t.end(); it++)
  {

  pVector(*it);
  cout << endl;

  }

  return 0;

}





