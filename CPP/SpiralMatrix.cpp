// Practice prove that for problem of this kind.
// 1.   With 4 identical or similar operation right, down, left and up. The program could shalt and any one of then, then it is not practical to write the program in 4 sperate loops like the program below.
// 2.   In this case, test case like [2,3] would end at the second step down, which leads to the requirement of judge of halt of program at each step.
// 3.   To hand the case of [1] is hard as well, because for the 4 steps, right, down, left and up all of them will defer the one step to the next, which result in another judgement of if there is only 1 element left. However, this is hard if the test case is not with only one element. The judgement will involve side effect with other conditions. The program is not debugable.
// 4.   Therefore, a set, map or vector of the direction that each step is going is neccessary. Movement for all directions is coded as one sub program. At first, it might not straigh forward to code the directions, but with a map of 0 , 1 , -1, 0 as a increment unit is enough. 
#include<vector>
#include<iostream>
#include"util.hpp"

using namespace std;

class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        
        vector<int> res;
        
        int nRow = matrix.size();
        
        if(0 == nRow)
            return res;
        
        int nCol = matrix[0].size();
        
        if(1==nRow && 1 == nCol){
            res.push_back(matrix[0][0]);
            return res;
        }
        
        int total = nRow*nCol-1;
        
        int m = 0;
        int n = 0;
        
        int i = nCol-1;
        int j = nRow-1;
        int count = 0;
        while(1)
        {
                if(i <= 0 && j <= 0 && count == total)
                {
                        res.push_back(matrix[m][n]);
                        break;
                }

                for(int k = 0; k != i; ++k){
                    res.push_back(matrix[m][n]); 
                    ++n;
                    ++count;

                }

            
                for(int k = 0; k != j; ++k){
                    res.push_back(matrix[m][n]); 
                    ++m;
                    ++count;

                }
                

                for(int k = 0; k != i; ++k){
                    res.push_back(matrix[m][n]); 
                    --n;
                    ++count;

                }

                //cout << m << n << endl;
                //cout << j << endl;
                for(int k = 0; k != j; ++k){
                    res.push_back(matrix[m][n]); 
                    --m;
                    ++count;

                }
                //cout << m << n << endl;

                ++m;
                ++n;
                //cout << m << n << endl;
                j-=2;
                i-=2;
                
        }
        return res;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        
        int len = matrix.size();
        
        vector<int> res;
        
        if(0 == len)
            return res;
        
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        int nEle = nRow*nCol;    
        
        int i = 0;
        int j = 0;
        
        int incremental_X[4] = {1,0,-1,0};
        int incremental_Y[4] = {0,1,0,-1};
        int incrementLen[2] = {nRow-1, nCol};
        
        // size of the matrix
        int side = 0;
        
        //direction of x and y
 
        
        
        int count = 0;
        
        int side_walk = 0;
        
        //res.push_back(matrix[0][0]);
        int m = 0;
        int n = -1;
        
        while(1){

    //        cout << m << " " <<n << endl;
     //       cout << side << endl; 
            int incre_X = incremental_X[side%4];
            int incre_Y = incremental_Y[side%4];
            int incre_L = incrementLen[(side+1)%2];

      //      cout << incre_X << " " << incre_Y << endl;
            cout << incre_L << endl<<endl;
            if(0 >= incre_L)
                break;
                
            for(int j = 0; j != incre_L; ++j)
            {
                n+=incre_X;
                m+=incre_Y;
                res.push_back(matrix[m][n]);
            }
            incrementLen[(side+1)%2]--;
            ++side;

        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<int> > matrix;
    matrix.push_back({1,2,3,4});      
    matrix.push_back({7,8,9,5});      
    matrix.push_back({6,6,1,6});      
    matrix.push_back({5,5,2,7});      
    matrix.push_back({4,4,3,8});      
    matrix.push_back({3,2,1,9});      

    /*
    matrix.push_back({1,2,3});      
    matrix.push_back({4,5,6});      
    matrix.push_back({7,8,9});      
    */
//   matrix.push_back({3});      
//   matrix.push_back({2});      
    pVector(S.spiralOrder(matrix));
}
