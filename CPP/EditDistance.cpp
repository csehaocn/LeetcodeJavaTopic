// The stupid mistake was made for some DP[m][n] (in the return ) was written as DP[m][m]
// The result for this is dp_helper return doesnt match with in the DP table. 
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    // We ll solve this problem by 2 Dimensional DP
    vector<vector<int> > DP;
    
    int dp_helper(const string &word1, const string& word2, int len1, int len2, int m, int n)
    {
        if(-1 != DP[m][n] || 0 == m || 0 == n)
        {
            return DP[m][n];
        }
        else
        {
            if(word1[m -1] == word2[n -1])
            {
                DP[m][n] = dp_helper(word1, word2, len1, len2, m-1, n-1);
                return DP[m][n];
            }
            else
            {
                int ins = dp_helper(word1, word2, len1, len2, m, n-1)+1;
                int del = dp_helper(word1, word2, len1, len2, m-1, n)+1;
                int rep = dp_helper(word1, word2, len1, len2, m-1, n-1)+1;
                int mMin = min(ins, del);
                mMin = min(mMin, rep);
                DP[m][n] = mMin;
                return DP[m][n];
            }
            return DP[m][n];
        }
            return DP[m][n];
    }
    
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        DP = vector<vector<int> >(len1+1, vector<int>(len2+1, -1));

        for( int i = 0; i != len1+1; ++i)
        {
            DP[i][0] = i;
        }
        for( int i = 0; i != len2+1; ++i)
        {
            DP[0][i] = i;
        }
        
        int result = dp_helper(word1, word2, len1, len2, len1, len2);

        cout << result << endl;
        
        return DP[len1][len2];
    }
       
};

int main()
{
    Solution S;
    string word1 = "";
    string word2 = "a";
    cout << S.minDistance(word1, word2);
    return 0;
}
