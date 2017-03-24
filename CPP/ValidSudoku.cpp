class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        
        int len = board.size();
        
        vector<bool> tmp(len, false);
        vector<bool> rowVeriVec = tmp;
        vector<bool> colVeriVec = tmp;
        
        for(int i = 0; i!=len; ++i)
        {
            rowVeriVec = tmp;
            colVeriVec = tmp;
        for(int j = 0; j!=len; ++j)
        {
            char c = board[i][j];
            if(c != '.')
            {
                int n = c-'0'-1;
                if(rowVeriVec[n] == true)
                    return false;
                else
                    rowVeriVec[n] = true;
            }
            
            c = board[j][i];
            
            if(c != '.')
            {
                int n = c-'0'-1;
                if(colVeriVec[n] == true)
                    return false;
                else
                    colVeriVec[n] = true;
            }
        }
        }
        
        for(int i = 0; i!=3; ++i)
        for(int j = 0; j!=3; ++j)
        {
            vector<bool> boxVeriVec = tmp;
            for(int m = 0; m!=3; ++m)
            for(int n = 0; n!=3; ++n)
            {
                char c = board[3*i+m][3*j+n];
                if(c != '.')
                {
                    int n = c-'0'-1;
                    if(boxVeriVec[n] == true)
                        return false;
                    else
                        boxVeriVec[n] = true;
                }
            }
        }
        return true;
    }
};
