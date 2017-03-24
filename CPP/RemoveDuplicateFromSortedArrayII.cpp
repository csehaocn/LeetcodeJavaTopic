// A mistake happend here, the first version I have 
// 
// for(int i = c; i != min(r, c+2); ++i)
// 
// However, the boundary condition min(r, c+2) is being kept modified in the body
// {
//     A[l] = A[c];
//     ++c;
//     ++l;
// }
//


// int u = min(r, c+2);
// for(int i = c; i != u; ++i)
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        
        if(0 == n)
            return 0;
            
        if( 2 >= n)
            return n;
            
        int l = 0;
        int c = 0;
        int r = 1;
        while(c != n)
        {
            while(r != n && A[r] == A[r-1] )
            {
                ++r;
            }
            int u = min(r, c+2);
            for(int i = c; i != u; ++i)
            {
                A[l] = A[c];
                ++c;
                ++l;
            }
            c= r;
            r++;
        }
        
        return l;
    }
};
