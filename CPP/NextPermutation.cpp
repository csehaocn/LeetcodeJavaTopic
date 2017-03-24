#include<iostream>
#include<vector>
#include<algorithm>
#include"util.hpp"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        
        int len = num.size();
        
        if(0 == len)
            return;
        else if(1 == len)
            return;
        else if(2 == len){
            swap(num[0], num[1]);
            return;   
        }
        else
        {
        
        int index = len -1;
        while(0 != index && num[index - 1] >= num[index])
        {
            --index;
        }
    
        int swp_index = index;
        for(int i = index+1; i != len; ++i)
        {
            if(num[i] > num[index-1])
                swp_index = i;
        }

        if(0 != index)
        swap(num[swp_index], num[index -1]);
        
        sort(num.begin()+index, num.end());
        
        return;
        }
        return;
    }

};


int main()
{
    Solution S;
    vector<int> num = {3,2,1};
    S.nextPermutation(num);
    pVector(num);
}
