#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

class Solution {

        
        vector<vector<int> > twoSum(vector<int>::iterator lit, vector<int>::iterator rit, int target) {

            vector<vector<int> > result;

            while(lit < rit)
            {
                if(*lit+*rit == target) 
                {
                    vector<int> temp;
                    temp.push_back(*lit);
                    temp.push_back(*rit);
                    result.push_back(temp);
                    do
                    {
                        ++lit;
                        --rit;
                    }while(*lit == *(lit-1) && *rit == *(rit+1) && lit < rit);
                }
                else if(*lit + *rit < target)
                {
                    lit++; 
                }
                else{
                    rit--;
                }

            }

            return  result;
            
        }

    public:

        vector<vector<int> > threeSum(vector<int> &num) {

            set<int> numSet;

            vector<vector<int> > res;

            int len = num.size();

            if(0 == len)
                return res;

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

                vector<vector<int> > temp = twoSum(num.begin()+i+1, num.end()-1, -1*num[i]);

                for(auto it2 = temp.begin(); it2 != temp.end(); ++it2)
                {
                    it2->push_back(num[i]);
                    sort(it2->begin(), it2->end(), std::less<int>());
                    res.push_back(*it2);
                }
            }
            return res;
                 
        }
};

int main(){
    static int arr[] = {-1,0,1,2,-1,-4};
    Solution S;
    vector<int> temp(arr, arr+6);
    auto i = S.threeSum(temp);
    for(auto it = i.begin(); it != i.end(); it++)
    {
        vector<int> t = *it; 
        for(auto it2 = t.begin(); it2 != t.end(); ++it2)
        {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    return 0;
}
