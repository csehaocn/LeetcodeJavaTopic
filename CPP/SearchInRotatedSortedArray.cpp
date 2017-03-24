class Solution {
public:
    int search(int A[], int n, int target) {
        
        if(1 == n)
        {
            if(A[0] == target)
                return 0;
            else
                return -1;
        }
        
        if(2 == n)
        {
            if(A[0] == target)
                return 0;
            if(A[1] == target)
                return 1;    
                
                return -1;
        }
        
        int pivot_index = n/2;
        int pivot_num = A[pivot_index];
        int l = A[0];
        
        if(pivot_num == target){
            return pivot_index;
        }

            if(pivot_num > l){
                if(pivot_num > target && l <= target){
                   int r = search(A, pivot_index, target);
                    return r;
       
                }
                else{
                    int r = search(A+pivot_index+1, n - pivot_index -1, target);
                    
                    return -1 == r? -1: pivot_index+1+r;
                }
            }
            else
            {
                if(pivot_num < target && l > target){
                    int r = search(A+pivot_index+1, n - pivot_index -1, target);
                    return -1 == r? -1: pivot_index+1+r;
                }
                else{
                    int r = search(A, pivot_index, target);
                    return r;
                }
            }
            
            return -1;
    }
};
