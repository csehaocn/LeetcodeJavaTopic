#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        const char* l = s;
        const char* r = s-1;
        
        if(*s == '\0')
            return 0;
            
        bool in_word = false;
            
        while(1)
        {
            if(*s == ' ' || *s == '\0'){
                if(in_word == true)
                {
                    r = s;
                    in_word = false;
                }
            }
            else
            {
                if(false == in_word ){
                    in_word = true;
                    l = s;
                }
                else{
                    in_word = true;
                }
            }
            if(*s == '\0')
                break;
            ++s;
            
        }

        return l <=r? r - l: 0;
    }
};

int main()
{
    Solution S;
    cout << S.lengthOfLastWord(" a");
}
