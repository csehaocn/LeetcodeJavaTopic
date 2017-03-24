#include<iostream>

using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {
        
        if( 0 == n)
            return;
            
        int col[3] = {0, 0, 0};
            
        for(int i = 0; i != n; ++i)
        {
            int c = A[i];
            A[col[c]] = c;
            col[c]++;
            
            for(int k = c+1; k <=2; ++k)
            {
// Be very carefull with the single char for variable that you use. Cause a lot of problem since you will be confused by their underlying meaning.                
                if(col[k] < col[k-1])
                {
                    col[k] = col[k-1];
                }
                else
                {
                    A[col[k]] = k;
                    col[k]++;
                }
            }
            
        }
        
        return;
    }
};

int main()
{
    int A[1] = {0};
    Solution S;
    S.sortColors(A,1);
    cout << A[0] << endl;
}
