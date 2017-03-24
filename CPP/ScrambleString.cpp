#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
    // start i, start j, len
    vector<vector<vector<int> > > DP;
    string m_s1;
    string m_s2;
    int lenTotal;
    bool DP_Helper(int i, int j, int len){
            cout << "ijlen" << i << j << len<< endl;
        if(DP[i][j][len] != -1){
            return DP[i][j][len];
        }
        else if(i + len > lenTotal || j + len > lenTotal)
        {
            DP[i][j][len] = 0;
        }
        else if(1 == len)
            if(m_s1[i] == m_s2[j])
                DP[i][j][len] = 1;
            else
                DP[i][j][len] = 0;
        else {
            // len will never be 0
            for(int k = 1; k != len; ++k){
                bool c1 = false;
                bool c2 = false;
                c1 = DP_Helper(i, j, k) && DP_Helper(i+k, j+k, len-k);
                c2 = DP_Helper(i, j+len - k, k) && DP_Helper(i+k, j, len-k);
                if(c1 || c2){
                    DP[i][j][len] = 1;
                    break;
                }
            }
            if(-1 == DP[i][j][len])
                DP[i][j][len] = 0;
        }
        cout << "ijlenDP" << i << j << len<< DP[i][j][len] << endl;
        
        return DP[i][j][len];
        
    }
    
public:
    bool isScramble(string s1, string s2) {
        m_s1 = s1;
        m_s2 = s2;
        int lenS1 = m_s1.size();
        int lenS2 = m_s2.size();
        if(lenS1 != lenS2)
            return false;
        lenTotal = lenS1;
        
        DP = vector<vector<vector<int> > >(lenTotal, vector<vector<int> >(lenTotal, vector<int>(lenTotal+1, -1)));
        
        return DP_Helper(0, 0, lenTotal);
        
    }
};

int main(){
    Solution S;
    string s1;
    string s2;
    s1 = "abc";
    s2 = "cba";
    cout << (S.isScramble(s1, s2) ? "true":"false") << endl;
    return 0;
}
