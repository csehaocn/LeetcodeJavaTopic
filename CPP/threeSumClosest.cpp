#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
    public:
        int twoSumClosest(vector<int> &num, int target){
            auto itb = num.begin();
            auto ite = num.end();
            int ret = *itb+*(ite-1);
            vector<int> result;
            while(itb<ite-1){
                if(abs(*itb+*(ite-1)-target)<abs(ret-target)){
                    ret = *itb+*(ite-1);
                    result.clear();
                    result.push_back(*itb);
                    result.push_back(*(ite-1));
                }
                if(*itb+*(ite-1) > target){
                    ite--;
                }else{
                    itb++;
                }
            }
            return ret;
        }
        int threeSumClosest(vector<int> &num, int target) {
            vector<int> copy(num);
            sort(copy.begin(),copy.end());
            int ret = num[0]+ num[1]+num[2];  
            for(auto it = copy.begin(); it != copy.end()-2; it++){
                vector<int> temp(it+1,copy.end()); 
                int two = twoSumClosest(temp, target-*it);
                if(abs(two+*it-target)<abs(ret-target)){
                    ret = two + *it;
                }
            }
            return ret;
        }
};

int main(){
Solution s = Solution();
vector<int> vec = {1,2,3,4,5};
vec = {-1,2,1,-4};
vec = {1,1,1,0};
cout<<s.threeSumClosest(vec,100);
return 0;
}
