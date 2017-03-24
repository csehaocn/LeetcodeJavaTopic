#include<iostream>
#include<vector>
#include"util.hpp"

using namespace std;

class Solution {
    
    vector<string> make_res(int A[], int n)
    {
        vector<string> res;
        for(int i = 0; i != n; ++i){
            res.push_back(string(A[i], '.') + string("Q") + string(n- A[i]-1,'.'));
        }
        return res;
    }
    // n size of board
    // i the ith row
    // A[] board status in row
    void DFS(int n, int i, int A[], vector<vector<string> > &res)
    {
        
        for(int j = 0; j != n; ++j){

            bool valid = true;

            for(int k = 0; k != i; ++k){

                if(A[k] == j || A[k] == j + i - k || A[k] == j - i + k)
                {
                    valid = false;
                    break;
                }
            }

            if(valid)
            {
                A[i] = j;
                if(i == n-1){
                    res.push_back(make_res(A, n));
                }
                else{
                    DFS(n, i+1, A, res);
                }
            }
        }
        
        A[i] = -1;
        return;
    }
    
public:
    vector<vector<string> > solveNQueens(int n) {
        int *A = new int[n];
        for(int i = 0; i != n; ++i){
            A[i] = -1;
        }
        vector<vector<string> > res;
        DFS(n, 0, A, res);
        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<string> > r = S.solveNQueens(1);
    cout << r.size() << endl;
    pVector(r[0]);
}

