/**************************************************************************
 * 
 *   File :       Median.cpp
 *   Created:     11/14/13
 *   Author:      Hao Wang
 *
 * ------------------------------------------------------------------------
 *
 * COPYRIGHT AIMLAB UNIVERSITY OF OREGON, 2013.
 * All rights reserved.
 * 
 * ------------------------------------------------------------------------
 *   
 * Revision history:
 *  11/14/13  Hao first issue
 *
 *************************************************************************/

/**************************************************************************
 * Description:  
 *
 * Argument:     
 *
 * Return value:
 *************************************************************************/

#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        vector<int> va;
        vector<int> vb;
        if(0==m)
            va = vector<int>(); 
        else
            va = vector<int>(&A[0], &A[0]+m); 
        if(0==n)
            vb = vector<int>(); 
        else
            vb = vector<int>(&B[0], &B[0]+n); 

        if(0 == m && 0 == n)
            return 0;
        else if(0 == m)
            va = vb;
        else if (0 == n)
            vb = va;
        auto al = va.begin(); 
        auto ar = va.end()-1; 
        auto bl = vb.begin(); 
        auto br = vb.end()-1; 
        while((ar-al)+(br-bl)>0){
            if(al>ar)
                bl++;
            else if (bl>br) 
                al++;
            else if(*al>*bl)
                bl++;
            else
                al++;
            if(al>ar)
                br--;
            else if(bl>br) 
                ar--;
            else if(*ar<*br)
                br--;
            else
                ar--;
        }
        //cout<<ar-al<<endl;
        //cout<<br-bl<<endl;
        auto pq = priority_queue<int>();
        if (ar == al)
            pq.push(*al);
        else if(1 == ar - al){
            pq.push(*al);
            pq.push(*ar);
        }
        if (br == bl)
            pq.push(*bl);
        else if(1 == br - bl){
            pq.push(*bl);
            pq.push(*br);
        }
        if (1 == pq.size())
            return pq.top();
        if (2 == pq.size()){
            double l = pq.top();
            pq.pop();
            double r = pq.top();
            return (l+r)/2; 
        }
        if (3 == pq.size()){
            pq.pop();
            return pq.top(); 
        }
        if (4 == pq.size()){
            pq.pop();
            double l = pq.top();
            pq.pop();
            double r = pq.top();
            return (l+r)/2; 
        }
    }
};

int main(){
    Solution s;
    //int A[4] = {3,6,9,10};
    //int B[4] = {1,5,8,22};
    //double result = s.findMedianSortedArrays(A, 4, B, 4);
    int A[0] = {};
    int B[1] = {1};
    double result = s.findMedianSortedArrays(A, 1, B, 4);
    cout<<result;
    return 0;
}
