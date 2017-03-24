public class Solution {
    
    // DFS is not the optimal choice, finishing one DFS might result in a very deep branches, close to 0.
    // Set up a queue of frontiers? BFS?
    public void DFS(int[][] rooms, int i, int j, int m, int n, int dist){
        rooms[i][j] = dist;
        
        if(i-1 >= 0){
            if(-1 != rooms[i-1][j] && dist+1 < rooms[i-1][j])
                DFS(rooms, i-1, j, m, n, dist+1);
        }
        
        if(i+1 < m){
            if(-1 != rooms[i+1][j] && dist+1 < rooms[i+1][j])
                DFS(rooms, i+1, j, m, n, dist+1);
        }
        
        if(j-1 >= 0){
            if(-1 != rooms[i][j-1] && dist+1 < rooms[i][j-1])
                DFS(rooms, i, j-1, m, n, dist+1);
        }
        
        if(j+1 < n){
            if(-1 != rooms[i][j+1] && dist+1 < rooms[i][j+1])
                DFS(rooms, i, j+1, m, n, dist+1);
        }
        
        return;
    }
    
    public void wallsAndGates(int[][] rooms) {
        int m = rooms.length;
        if(0 == m)
            return;
        int n = rooms[0].length;
        if(0 == n)
            return;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                if(0 == rooms[i][j]){
                    DFS(rooms, i, j, m, n, 0);
                }
            }
            
        return;
    }
}
