public class Solution {
    
    int[] id;
    int[] weight;
    
    public int find(int x){
        int k = x;
        while(k != id[k]){
            k = id[k];
        }
        // PathCompression
        while(id[x] != k){
            x = id[x];
            id[x] = k;
        }
        return k;
    }
    
    public void union(int rX, int rY){
        if(weight[rX] == weight[rY]){
            id[rX] = rY;
            weight[rY]++;
        }else if(weight[rX] < weight[rY]){
            id[rX] = rY;
        }else{
            id[rY] = rX;
        }
        
        return;
    }
    
    public int countComponents(int n, int[][] edges) {
        // Union find...
        if(0 == n)
            return 0;
        
        id = new int[n];
        weight = new int[n];
        for(int i = 0; i != n; ++i){
            id[i] = i;
            weight[i] = 1;
        }
        
        int len = edges.length;
        //System.out.println("len = " + len);
        if(0 == len)
            return n;
            
        for(int i = 0; i != len; ++i){
            
            int x = edges[i][0];
            int y = edges[i][1];
            int rX = find(x);
            int rY = find(y);
            // Error : if rX == rX ......
            if(rX == rY)
                continue;
            else{
                union(rX, rY);
            }
        }
        
        int res = 0;
        for(int i = 0; i != n; ++i){
            //System.out.println(id[i]);
            if(id[i] == i)
                res++;
        }
        return res;
    }
}
