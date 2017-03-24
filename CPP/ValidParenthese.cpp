#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;

        map<char, char> m; 

        m['{'] = '}';
        m['('] = ')';
        m['['] = ']';

        int len = s.size();

        if(0 == len)
            return true;

        for(int i = 0; i!= len; ++i)
        {
            if(m.find(s[i]) != m.end())
            {
                stk.push(s[i]);
            }

            if(s[i] == '}' || s[i] == ')' || s[i] == ']')
            {
                if( !stk.empty() && m[stk.top()] == s[i])
                {
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }

        return stk.empty();
    }
};

int main(){
    Solution S;

    cout << S.isValid(string("{{}}"));
}
