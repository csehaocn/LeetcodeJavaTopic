#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        int len = s.size();
        
        int res = 0;
        
        if(0 == len){
            return res;
        }
        
        map<char, int> rm;
        
        rm['I'] = 1;
        rm['V'] = 5;
        rm['X'] = 10;
        rm['L'] = 50;
        rm['C'] = 100;
        rm['D'] = 500;
        rm['M'] = 1000;

        for(int i = 0; i!=len-1; ++i)
        {
            if(rm[s[i]] < rm[s[i+1]])
            {
               res -= rm[s[i]]; 
            }
            else
            {
                cout << "b";
                res += rm[s[i]];
            }
            cout << res << endl;
        }
        
        res += rm[s[len-1]];
        
        return res;
    }
};

int main()
{
    Solution S;
    string s("DCXXI");
    cout << S.romanToInt(s);
}
