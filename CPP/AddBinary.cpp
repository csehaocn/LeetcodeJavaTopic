#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {

            string res;

            string reversed_a(a.rbegin(), a.rend());
            string reversed_b(b.rbegin(), b.rend());
            
            cout << reversed_a << endl;
            cout << reversed_b << endl;

            int carry = 0;

            int size_a = a.size();
            int size_b = b.size();

            int max_size = max(size_a, size_b);

            for(int i = 0; i !=max_size; ++i)
            {

                int sum = 0;

                cout << i;
                // stupid mistake, use a instead of the reversed.
                //sum += i < size_a ? (a[i] -'0') : 0;
                sum += i < size_a ? (reversed_a[i] -'0') : 0;

                cout << a[i]-'0';

                //sum += i < size_b ? (b[i] -'0') : 0;
                sum += i < size_b ? (reversed_b[i] -'0') : 0;

                cout << b[i]-'0';

                sum += carry;

                cout << sum << endl;

                carry = sum/2;

                sum %= 2;

                res.push_back(sum+'0');
            }

            if(carry)
                res.push_back('1');

            return string(res.rbegin(), res.rend());
        }

};

int main()
{
    Solution S;
    cout << S.addBinary("1010", "1011");
}
