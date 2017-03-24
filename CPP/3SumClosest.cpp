#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <utility> 
#include <cmath>
#include <limits>
#include <values.h>

using namespace std;


class Solution {

        
        int twoSumCloset(vector<int>::iterator lit, vector<int>::iterator rit, int target) {

            int m = INT_MAX;

            while(lit < rit)
            {

                if( abs( *lit+*rit - target ) < abs(m) ) 
                {
                    m = *lit+*rit-target;
                }

                if( *lit+*rit < target) 
                {
                    ++lit;
                }
                else{
                    --rit;
                }

            }

            return  m;
            
        }

    public:

    int threeSumClosest(vector<int> &num, int target) {

            int m = INT_MAX;

            vector<int> res;

            set<int> numSet;

            int len = num.size();

            if(0 == len)
                return 0;

            for(auto it= num.begin(); it!=num.end(); it++)
            {
                numSet.insert(*it);
            }

            sort(num.begin(), num.end());

            for(int i = 0; i != len; ++i)
            {
                if(i != 0 && num[i] == num[i-1]) 
                {
                    continue;
                }

                int t = twoSumCloset(num.begin()+i+1, num.end()-1, target-1*num[i]);
                
                
                if( abs(t) < abs(m))
                {
                    m = t; 
                }

            }
            return m+target;
        }
};

int main(){
    static int arr[] = {-1,0,1,2,-1,-4};
    Solution S;
    vector<int> temp(arr, arr+6);
    auto i = S.threeSumClosest(temp,100);
    cout << i;
    /*
    for(auto it = i.begin(); it != i.end(); it++)
    {
        {
            cout << *it << " ";
        }
    }
    */
    return 0;
}
