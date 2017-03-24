#include<vector>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

class Solution {


    public:

        bool judgeValid(string s){

            if(s.size()>1 && '0' == s[0]){
                //cout<<s<<endl;
                return false;
                }

            std::string myString = s;
//            cout<<s<<endl;
            int value = atoi(myString.c_str());
            if (value >= 0 && value < 256)
                return true;
            else
                return false;

        }

        vector<string> restoreIpAddresses(string s) {

            vector<string> result = vector<string>();

            int size = s.size();

            if(size > 12)
                return result;

            int a[13][13] = {0};

            for(int p = 1; p <= size; p++)
                for(int r = p; r <= size && r<p+3; r++)
                    if(judgeValid(s.substr(p-1,r-p+1)))
                        a[p][r] = 1;

            for(int i = 1; i < size; i++)
                for(int j = i+1; j<=i+3 && j < size; j++)
                    for(int k = j+1; k<=j+3 && k < size; k++){
                        if(k+3 >= size){
                            if(1 == a[1][i] && 1 == a[i+1][j] && 1 == a[j+1][k] && 1 == a[k+1][size]){
                                string temp = s;
                                temp.insert(i,".");
                                temp.insert(j+1,".");
                                temp.insert(k+2,".");
                                result.push_back(temp);
                            }
                        }

                    }
            return result;
        }

};

int main(){
    Solution s;
    string a = "010010";
    vector<string> c = s.restoreIpAddresses(a);
    cout<<" ";
return 0;
}
