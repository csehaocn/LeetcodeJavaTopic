#include<vector>
#include<map>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        
        int len = num.size();
        if(0 == len)
            return 0;
        
        int res = -1;
        // a map from element, to visited or not
        unordered_map<int, bool> eleStatMap;
        
        for(int i = 0; i != len; ++i){
            eleStatMap[num[i]] = false;
        }
        
        for(auto iter = eleStatMap.begin(); iter != eleStatMap.end(); ++iter){
            int conLen = 1;
            if(iter->second == false){
                int conLen = 1;
                int ele = iter->first;
                cout << "ele" <<ele << endl;
                int j = ele+1;
                while(eleStatMap.find(j) != eleStatMap.end()){
                    ++conLen;
                    // visited
                    eleStatMap[j] = true;
                    ++j;
                }
                
                j = ele-1;
                while(eleStatMap.find(j) != eleStatMap.end()){
                cout << j << endl;
                    ++conLen;
                    cout << conLen << endl;
                    // visited
                    eleStatMap[j] = true;
                    --j;
                }
                
                eleStatMap[ele] = true;
            }
            cout << conLen << endl; 
            res = max(res, conLen);
        }
        
        return res;
        
    }
};

int main(){
    Solution s;
    vector<int> num = {0, -1};
    s.longestConsecutive(num);    
}
