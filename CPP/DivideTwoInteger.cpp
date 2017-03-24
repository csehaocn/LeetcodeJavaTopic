#include<iostream>
#include<limits.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        int sign = 1;

        if(dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0 )
            sign = -1; 

        long long divid = abs((long long)dividend);
        long long divd = abs((long long)divisor);
        long long div = divd; 

        int quot = 0;
        int mult = 1;

        while(divid >= div)
        {
        //    cout << dividend << endl;
            while( divid - div >= div)
            {
         //       cout << dividend - div << " " << div << endl;
                div = div << 1;
                mult = mult << 1;
            }

            quot += mult;
            divid -= div;
            mult = 1;
            div = divd;
        }
        
        return sign*quot;
        /*
        10/2
        quot 5
        divident 2 
        divisor 2
        mult 1
        div 2
        */
    }
};

int main(){
    Solution S;
    cout << S.divide(2, 2);
//    cout << sizeof(int*);
}
