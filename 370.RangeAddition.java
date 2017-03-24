public class Solution {
    // Note: typical application of accumulation sum, spread out the incremental and decremental points, then iterate through and accumulate.
    public int[] getModifiedArray(int length, int[][] updates) {
        int[] inc = new int[length];
        for(int i = 0; i != updates.length; ++i){
            int[] u = updates[i];
            inc[u[0]] += u[2];
            // Error: the value should be deducted after the index
            // inc[u[1]]
            if(u[1]+1 < length)
                inc[u[1]+1] -= u[2];
        }
        for(int i = 1; i != length; ++i){
            inc[i] += inc[i-1];
        }
        return inc;
    }
}
