public class TicTacToe {

    /** Initialize your data structure here. */
    int n;
    int[][] board;
    
    public TicTacToe(int n) {
        this.n = n;
        board = new int[n][];
        for(int i = 0; i != n; ++i){
            board[i] = new int[n];
        }
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int move(int row, int col, int player) {
        board[row][col] = player;
        for(int i = 0; i != n; ++i){
            if(player != board[row][i]){
                break;
            }else{
                if(i == n-1)
                    return player;
            }
        }
        
        for(int i = 0; i != n; ++i){
            if(player != board[i][col]){
                break;
            }else{
                if(i == n-1)
                    return player;
            }
        }
        
        if(row == col){
            for(int i = 0; i != n; ++i){
                if(player != board[i][i]){
                    break;
                }else{
                    if(i == n-1)
                        return player;
                }
            }
        }
        
        if(row == n-col-1){
            for(int i = 0; i != n; ++i){
                if(player != board[i][n-i-1]){
                    break;
                }else{
                    if(i == n-1)
                        return player;
                }
            }
        }
        
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
