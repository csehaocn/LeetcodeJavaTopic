// There are so many places that makes it a bug.
#include<string>
#include<iostream>
#include<vector>
#include"util.hpp"
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {

        string res;
        vector<int> sq(n);
        
        vector<int> po(n+1);
        // po and sq are not initialized correctly
        po[0] = 1;
        po[1] = 1;
        for(int i = 2; i < n+1; ++i){
            po[i] = po[i-1]*i;
        }
        for(int i = 0; i < n; ++i){
            sq[i] = i+1;
        }
        for(int i = n; i !=1; --i){
            int di = (k-1)/po[i-1];
            k -= di*po[i-1];
            // the sq[di] didn't add the '0' in the first time.
            res.push_back(sq[di]+'0');
            // the erase was done at the wrong place at (di-1)
            // The symptome of the bug is very wierd. The program went out of the loop and even return the function, then crashed. I think the erase operates as normal, but modified some critical section on the stack which handicapes the operation of destructor. 
            sq.erase(sq.begin()+di);
        }
            
        res.push_back(sq[0]+'0');
        return res;
    }
};

int main(){
    Solution S;    
    cout << S.getPermutation(9, 1);
}
