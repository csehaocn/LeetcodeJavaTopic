class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        
        // might not be used
        bool res;
        
        int nRow = matrix.size();
        
        if(0 == nRow)
            return false;
        
        int nCol = matrix[0].size();
        
        if( 0 == nCol)
            return false;
            
        /*
            E.g.
            1, 3, 4,
            6, 8, 10,
            14,16,18,
        */
        
        int rowIndex = -1;
        
        // index for divide and conquer
        int l = 0;
        int r = nRow;
        
        // if is before the first row
        if(target < matrix[0][0])
            return false;
        // if is in the last row
        if(target >= matrix[nRow-1][0])
            rowIndex = nRow - 1;
            
        // if not in the last row, not updated
        if( -1 == rowIndex)
        {
            // while there is more than 1 row in between
            while(l < r-1){
                int midIndex = l + (r - l)/2;
                // if in the upper rows
                if(target < matrix[midIndex][0]){
                    // change the lower bound r
                    r = midIndex;
                }
                // if not
                else
                {
                    l = midIndex;
                }
            }
            
            // update row Index
            rowIndex = l;
        }
        
        // Now we know the row index, start it again;
        
        l = 0; 
        r = nCol;
        // if out of range
        if(target < matrix[rowIndex][0] || target > matrix[rowIndex][nCol-1]) 
        {
            return false;
        }
        else
        {
            while(l < r-1){
                int midIndex = l + (r - l)/2;
                // if in the left range
                if(target < matrix[rowIndex][midIndex]){
                    // change the right bound r
                    r = midIndex;
                }
                // if not
                else
                {
                    l = midIndex;
                }
            }
            if(target == matrix[rowIndex][l])
                return true;
            else
                return false;
        }
        
        return false;
    }
};
