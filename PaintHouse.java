public class Solution {
    public int minCost(int[][] costs) {
        int len = costs.length;
        if(0 == len)
            return 0;
        
        int[] r = new int[2];
        int[] g = new int[2];
        int[] b = new int[2];
        
        r[0] = costs[0][0];
        g[0] = costs[0][1];
        b[0] = costs[0][2];
        
        for(int i = 1; i != len; ++i){
            int index = i%2;
            int pIndex = (i-1)%2;
            r[index] = costs[i][0] + Math.min(g[pIndex], b[pIndex]);
            g[index] = costs[i][1] + Math.min(b[pIndex], r[pIndex]);
            b[index] = costs[i][2] + Math.min(g[pIndex], r[pIndex]);
        }
        
        return Math.min(r[(len-1)%2], Math.min(g[(len-1)%2], b[(len-1)%2]));
    }
}
