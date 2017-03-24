#include<iostream>
#include<vector>
using namespace std;

class Solution {
        bool isInterleaveHelper(const string &s1, const string &s2, const string &s3, vector<vector<int> > &DPMatrix) {
            int b = DPMatrix[s1.size()][s2.size()];
            if(1==b)
                return true;
            else if (0 == b)
                return false;
            else{
                if(!s1.empty()){
                    if(s1[0] == s3[0] && isInterleaveHelper(s1.substr(1,s1.size()-1), s2, s3.substr(1,s3.size()-1), DPMatrix)){
                        DPMatrix[s1.size()][s2.size()] = 1;
                        return true;
                    }
                }
                if(!s2.empty()){
                    if(s2[0] == s3[0] && isInterleaveHelper(s1, s2.substr(1,s2.size()-1), s3.substr(1,s3.size()-1), DPMatrix)){
                        DPMatrix[s1.size()][s2.size()] = 1;
                        return true;
                    }
                }

                DPMatrix[s1.size()][s2.size()] = 0;
                return false;
            }
        }
   
    public:
        bool isInterleave(string s1, string s2, string s3) {
                if (s3.size() != s1.size() + s2.size())
                    return false;
                else{

                    vector<vector<int> > DPMatrix = vector<vector<int> >(s1.size()+1,vector<int>(s2.size()+1, -1));
                    DPMatrix[0][0] = 1;

                    return isInterleaveHelper(s1, s2, s3, DPMatrix);
                }

        }
};

int main(){
    Solution s = Solution();
    cout<<s.isInterleave("aabcc","dbbca","aadbbcbcac");
    cout<<s.isInterleave("aabcc","dbbca","aadbbbaccc");
    return 0;
}
