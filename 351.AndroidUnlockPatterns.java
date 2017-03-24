public class Solution {
    
    public int numberOfPatternsAux(int m, int n, int num, int[] visited, int[][] jump, int pathLen){
        
        if(n == pathLen || 9 == pathLen){
            return 1;
        }
        
        visited[num] = 1;
        
        int res = 0;
        for(int i = 1; i <= 9; ++i){
            if(num != i && 0 == visited[i]){
              if( 0 == jump[num][i] || ( 1 == visited[jump[num][i]] ) ){
                  // Error: visited is not set for the first element, recursive call pattern does not match for here and initial call in the main function.
                  // visited[i] = 1;
                  // visited[i] = 0;
                  // is a good paradigm, but not good for initial call with conditions. 
                  
                  // visited[i] = 1;
                  res += numberOfPatternsAux(m, n, i, visited, jump, pathLen+1);
                  // visited[i] = 0;
              }  
            }
        }
        if(pathLen >= m && pathLen <= n)
            res+= 1;
            
        visited[num] = 0;
        
        return res;
    }
    
    public int numberOfPatterns(int m, int n) {
        
        
        // Starts from 1, 2, 5
        // DFS
        // A visited array
        // A DS store jump path such as 1 -> 5 -> 9
        int[][] jump = new int[10][10];
        int[] visited = new int[10];
        
        jump[1][3] = 2;
        jump[3][1] = 2;
        jump[1][7] = 4;
        jump[7][1] = 4;
        jump[3][9] = 6;
        jump[9][3] = 6;
        jump[7][9] = 8;
        jump[9][7] = 8;
        
        jump[1][9] = 5;
        jump[9][1] = 5;
        jump[3][7] = 5;
        jump[7][3] = 5;
        jump[4][6] = 5;
        jump[6][4] = 5;
        jump[2][8] = 5;
        jump[8][2] = 5;
        
        // Error: this is the case we have to call multiple DFS with different initial conditions,
        // Forgot to setup different initial condition for visited.
        // visited[i] = 1;
        // res += numberOfPatternsAux(m, n, i, visited, jump, pathLen+1);
        // visited[i] = 0;
        // condition is set up before call of DFS in the aux function
        // but not set up for initial.
        int a = numberOfPatternsAux(m, n, 1, visited, jump, 1);
        int b = numberOfPatternsAux(m, n, 2, visited, jump, 1);
        int c = numberOfPatternsAux(m, n, 5, visited, jump, 1);
        
        return 4*a + 4*b + c;
        
    }
}
