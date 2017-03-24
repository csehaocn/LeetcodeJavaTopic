#include <iostream>
#include <cmath>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            string t = "";
            char a = 'A';
            char z = 'z';
            for(auto it = s.begin(); it != s.end(); it++){
                if (*it>=a && *it<=z)
                    t.append(1,*it);
            }
            cout << t;
            auto it1 = t.begin();
            auto it2 = t.end();
            while(it2>it1){
                cout<<*(it2-1) << *it1;
                if(*(it2-1)!=*it1 && abs(*(it2-1)-*it1) != 32)
                    return false;
                it2--;
                it1++;
            }
            return true;
        }
};

int main(){
#ifdef DEBUG
    cout<<"debuging";
#else
    cout<<"no debuging";
#endif    
    Solution s;

    cout<<s.isPalindrome("ab");
    return 0;
}
