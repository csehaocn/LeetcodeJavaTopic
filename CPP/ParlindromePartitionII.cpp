#include<string>
#include<vector>
#include<climits>
#include<iostream>
using namespace std;

class Solution {
    public:
        int minCut(string s) {

            int leng = s.size();

            int dp[leng+1];
            bool palin[leng][leng];

            for(int i = 0; i <= leng; i++)
                dp[i] = leng-i;
            for(int i = 0; i < leng; i++)
                for(int j = 0; j < leng; j++)
                    palin[i][j] = false;

            for(int i = leng-1; i >= 0; i--){
                for(int j = i; j < leng; j++){
                    if(s[i] == s[j] && (j-i<2 || palin[i+1][j-1])){
                        palin[i][j] = true;
                        dp[i] = min(dp[i],dp[j+1]+1);
                    }
                }
            }
            return dp[0]-1;
        }
};

class Solution2 {
public:
    int minCut(string s) {
        
        int len = s.size();
        
        if(0 == len)
            return 0;
            
        // the parlindrome table, record the parlindrome states from i to j
        vector<vector<bool> > DPParlin = vector<vector<bool> >(len+1, vector<bool>(len+1, false) );
        for(int i = 0; i < len; ++i){
            DPParlin[i][i+1] = true;
        }
        
        vector<int> DPMinCut = vector<int>(len+1, 0);
        DPMinCut[len] = -1;
        
        // iterate through the end
        for(int i = len-1; i >= 0; --i){
            // j is the index of the last parlindrom
                // the min cut at i must be at lease
                DPMinCut[i] = INT_MAX;
            for(int j = i+1; j <= len; ++j){
                // if parlin char
                if(s[i] == s[j-1]){
                    
                    DPParlin[i][j] = (j-1-i>2) ? DPParlin[i+1][j-1] : true;
                    // if is parlindrome
                    if(DPParlin[i][j] == true){
                        // update min cut
                        DPMinCut[i] = min(DPMinCut[i], DPMinCut[j]+1);
                    }
                }
                else{
                    // if not, can not be parlin
                    DPParlin[i][j] = false;
                }
                
            }
        }
        cout << DPMinCut[0] << endl;
        cout << DPMinCut[1] << endl;
        
        return DPMinCut[0];
    }
};


int main(){
Solution2 sol;
sol.minCut("bb");
return 0;
}
