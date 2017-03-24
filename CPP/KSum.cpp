#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
    public:

        vector<vector<int> > twoSum(vector<int> num, int target) {
            vector<vector<int> > result;
            if(num.size()<2)
                return result;
            auto itb = num.begin();
            auto ite = num.end();
            while(itb<ite-1){
                if(*itb+*(ite-1)==target){
                    vector<int> temp = vector<int>();
                    temp.push_back(*(ite-1));
                    temp.push_back(*itb);
                    if(result.empty()){
                        result.push_back(temp);
                    }else if((*(result.end()-1))[1] != *itb){
                        result.push_back(temp);
                    }
                    itb++;
                    ite--;
                }else if(*itb+*(ite-1) > target){
                    itb++;
                }else{
                    ite--;
                }
            }
            return result;
        }

        vector<vector<int> > KSum(int K, vector<int> num, int target) {
            if(2==K)
                return twoSum(num, target);

            vector<vector<int> > result;

            if(0 == K)
                return result;

            set<int> s;
            for(auto it=num.begin(); it != num.end(); it++){
                if (1==K){
                    if(*it == target && s.find(*it)==s.end()){
                        vector<int> temp;
                        temp.push_back(*it);
                        result.push_back(temp);
                        s.insert(*it);
                    }
                }else{
                    if(s.find(*it)==s.end()){
                        vector<int> para(it+1,num.end());
                        vector<vector<int> > ret = KSum(K-1, para, target - *it );
                        for(auto it2=ret.begin(); it2!= ret.end(); it2++){
                            it2->push_back(*it);
                        }
                        result.insert(result.begin(),ret.begin(),ret.end());
                        s.insert(*it);
                    }
                }
            }
            return result;
        }
        vector<vector<int> > fSum(vector<int> &num, int target) {
            vector<vector<int> > result;
            vector<int> para(num);
            sort(para.begin(),para.end(),greater<int>());
            result = KSum(4,para,target);
            return result;
        }
};

int main(){
Solution s = Solution();
vector<int> num = {0, 1 , 2 , 3 , -1, -2, -3 };
num = {1,0,-1,0,-2,2};
num = {0,1,5,0,1,5,5,-4};
vector<vector<int> > i = s.fSum(num,11);
for(auto it = i.begin();it!=i.end();it++){
    for(auto it2 = it->begin(); it2!=it->end(); it2++){
        cout<<*it2<<" ";
    }
    cout<<endl;
}
return 0;
}
