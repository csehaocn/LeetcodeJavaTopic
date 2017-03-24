class Solution {
public:
    int searchInsert(int A[], int n, int target) {
     
        if(0 == n)
            return 0;
        
        if(1 == n)
        {
            if(target > A[0])
            {
                return 1;
            }
            else
            {
                return 0;
            }
                
        }
        
        int pivot = A[(n+1)/2-1];
        
        if(pivot == target)
            return (n+1)/2-1;
        else if(pivot > target)
        {
            return searchInsert(A, (n+1)/2-1, target);
        }
        else
        {
            return (n+1)/2 + searchInsert(A+ (n+1)/2, n-(n+1)/2, target);
            
        }
        
    }
};
