class Solution {
public:
    int removeDuplicates(int A[], int n) {
        
        if(0 == n)
            return 0;
            
        int curr = 0;
        
        for(int i = 1; i != n; ++i)
        {
            if(A[curr] != A[i])
            {
                ++curr;
                A[curr]=A[i];
            }
        }
        
        return curr+1;
    }
};
