#include "util.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {

    double findKthTwoSorted(int A[], int m, int B[], int n, int k){
        int *pa = A, *pb = B;
        int sa = m, sb = n;
        while(1)
        {
            if(sa < sb)
            {
                swap(pa, pb);
                swap(sa,sb);
            }
                    cout << sa << " " << pa[0] << endl;
                   cout << sb << " " << pb[0] << endl;
                  cout << k << endl;
            if(0 == sb)
            {
                return pa[k-1];
            }
            else if(sa+sb == k)
                return max(pa[sa-1],pb[sb-1]);
            else if(1 == sb)
            {
                if(pb[0] >= pa[k-1])
                    return pa[k-1];
                else
                {
                    if(1 == k)
                        return pb[0];
                    else
                        return max(pa[k-2],pb[0]);
                }
            }

            if(1==k)
                return min(pa[0],pb[0]);


            if(k > sa/2 + sb/2)
            {
                if(pa[sa/2-1] > pb[sb/2-1])
                {
                    pb += sb/2;
                    k -= sb/2;
                    sb -= sb/2;
                }
                else
                {
                    pa += sa/2;
                    k -= sa/2;
                    sa -= sa/2;
                }
            }
            else
            {
                if(pa[sa/2-1] > pb[sb/2-1])
                {
                    sa = sa/2;
                }
                else
                {
                    sb = sb/2;
                }
            }
        }
    }


    public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2)
            return findKthTwoSorted(A, m, B, n, (m+n)/2+1);
        else 
            return (findKthTwoSorted(A, m, B, n, (m+n)/2) + findKthTwoSorted(A, m, B, n, (m+n)/2+1))/2.0;
    }
};


int main(){
    int a[] = {2};
    int b[] = {1,3};
    Solution s;
    cout << s.findMedianSortedArrays(a, 1, b, 2);
    return 0;
}
