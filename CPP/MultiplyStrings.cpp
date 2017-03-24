#include<iostream>
#include<string>
using namespace std;

class Solution {

public:
    string multiply(string num1, string num2) {

        int len1 = num1.size();
        int len2 = num2.size();
        
        string res(len1*len2+1,'0');
        
        int len = res.size();
        
        if(0 == len)
            return string("0");
            
        for(int i = len2-1; i != -1; --i){
            int carry = 0;
            int s2_num = num2[i]-'0';
            for(int j = len1-1; j != -1; --j){
                int s1_num = num1[j]-'0';
                int index = len-1-(len2-1-i+len1-1-j);
                //   cout << s2_num << s1_num << endl;
                int product = s2_num*s1_num+carry+(res[index]-'0');
                //  cout << product << endl;
                carry = product/10;
                product = product%10;
                //    cout << product << endl;
                //carry = product/10;
                //     cout <<"index" << index << endl;
                res[index] = '0'+product;
                //    cout << carry << endl;
            }
            int index = len-1-(len2-1-i+len1-1-(-1));

                //   cout << index<< endl;
                //   cout << carry<< endl;

            res[index] = '0'+carry;
        }

        //cout << res << endl;
        
        int index = 0;
        
        while(res[index] == '0')
            ++index;
        
        string result = string(res.begin()+index, res.end());

        if(result.empty())
            return "0";
        
        return result;
    }
};

int main()
{
    Solution S;
    string num1("23");
    string num2("19");
    cout << S.multiply(num1, num2);
}
