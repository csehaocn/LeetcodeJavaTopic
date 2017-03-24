class Solution {
public:
    bool verify(vector<vector<char> > &board, int i, int j)
    {
        for(int m = 0; m!=9; ++m){
            if( m != j && board[i][m] == board[i][j]){
                return false;
            }
        }
        
        for(int n = 0; n!=9; ++n){
             if( n != i && board[n][j] == board[i][j]){
                return false;
            }
        }
        
        int x = (i/3)*3;
        int y = (j/3)*3;
        for(int m = x; m != x+3 ; ++m )
            for(int n = y; n != y+3 ;++n){
            if( m != i && n != j && board[m][n] == board[i][j])
                return false;
        }
        
        return true;
    }
    
    bool DFS(vector<vector<char> > &board, int i, int j){
        
        if('.' == board[i][j])
        {
            for(int z = 1; z!= 10; ++z){
                board[i][j] = z + '0';
            
                bool valid = verify(board, i, j);
            
                if(valid)
                {
                    if(8 == i && 8 == j)
                    return true;
                    else if(8 == i){
                        if(true == DFS(board, 0, j+1)) return true;
                    }else{
                        if(true == DFS(board, i+1, j)) return true;
                    }
                }
            }
            board[i][j]='.';
            return false;
        }
        else{
                    if(8 == i && 8 == j)
                        return true;
                    else if(8 == i){
                        if(true == DFS(board, 0, j+1)) return true;
                    }else{
                        if(true == DFS(board, i+1, j)) return true;
                    }
        }
        
    }
  
    void solveSudoku(vector<vector<char> > &board) {
        DFS(board, 0,0);
    }
};
