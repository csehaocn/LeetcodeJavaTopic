public class Solution {

    private int[] nums;

    /*
    private void swap(int[] nums, int i, int j){
        if(i == j)
            return;
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }
    */

    public Solution(int[] nums) {
        this.nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        
        int[] ret = new int[nums.length];
        
        int len = ret.length;
        // Error: Array out of bound when i = 0, for [],  != is not a stop sign.
        for(int i = 0; i < len; ++i){
            int s = (int)(Math.random()*(i+1));
            ret[i] = ret[s];
            ret[s] = nums[i];
        }
        
        return ret;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
