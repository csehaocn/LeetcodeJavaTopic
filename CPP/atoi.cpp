#include<iostream>
#include<climits>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        
        int result = 0;
        int minus = 1;
        bool sign = false;
        bool numed = false;
        while(*str!='\0'){
            
            if(*str != ' '){
                
                if('-' == *str){
                    if(true == sign)
                        return 0;
                    minus *= -1;
                    sign = true;
                    numed = true;
                }
                else if('+' == *str)
                {
                     if(true == sign)
                        return 0;
                    minus *= 1;
                    sign = true;
                    numed = true;
                }
                else if(*str < '0' || *str > '9')
                {
                    break;
                }
                else
                {
                    numed = true;
                    
                    if(INT_MAX/10 < result  || *str-'0' > INT_MAX - result*10){
                        if(minus < 0)
                            return INT_MIN;
                        else
                            return INT_MAX;
                    }
                    else
                    {
                        result = result*10 + *str-'0';
                    }
                }
            }
            else
            {
                if(numed == true)
                return result*minus;
            }
            ++str;
        }
        return result*minus;
    }
};

int main()
{
    Solution S;
    cout << S.atoi("123");    
    return 0;
}
