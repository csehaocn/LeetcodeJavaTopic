#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution {
    public:
        string countAndSay(int n) {

            string res = string("1");
            string s;

            if(0 == n)
                return res;

            for(int i = 1; i!= n; ++i){
                s = res;
                res = string();
                int j = 0;
                int count = 1;
                while(j!=s.size())
                {
                    char c = s[j];
                    if(j!=s.size()-1 && s[j]==s[j+1])
                    {
                        ++count;
                    }
                    else
                    {
                        res.push_back(count+'0');
                        res.push_back(c);
                        count = 1;
                    }
                    ++j;
                }
            }
            return res;

        }
};

int main()
{
    Solution S;
    cout << S.countAndSay(4);
}
