#include<iostream>
#include"util.hpp"
using namespace std;

class Solution {
    public:
        int firstMissingPositive(int A[], int n) {
            for(int i = 0; i != n; ++i){
                int num = A[i];
                while( num <= n && num > 0 && num != i+1 && A[i] != A[num -1]){
                    swap(A[i], A[num-1]);
                    num = A[i];
                }
            }
            // Notice that we have to do it the second time, since -1, 3, 4, 2 ,1 the 1 could be swap back and miss the change to be put in the right position.
            // Notice that the second time is not completely working at all, since there will be something swap back again.
            /*
            for(int i = 0; i != n; ++i){
                int num = A[i];
                if( num <= n && num > 0 && num != i+1){
                    swap(A[i], A[num-1]);
                }
            }
            vector<int> B(A, A+n);
            pVector(B);
            */
            for(int i = 0; i != n; ++i){
                if(A[i]!=i+1){
                    return i+1;
                }
            }
            return n+1;
        }
};

int main()
{
    Solution S;
    int A[29] = {-3,9,16,4,5,16,-4,9,26,2,1,19,-1,25,7,22,2,-7,14,2,5,-6,1,17,3,24,-4,17,15};
    cout << S.firstMissingPositive(A,29);
    return 0;
}
