public class Solution {
    
    private void swap(int[] nums, int i, int j){
        if(i == j)
            return;
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }
    
    public void wiggleSort(int[] nums) {
        int len = nums.length;
        if(len < 2)
            return;
        
        boolean down = false;
        
        if(nums[0] > nums[1])
            swap(nums, 0, 1);
        
        for(int i = 2; i != len; ++i){
            
            if(down && nums[i] < nums[i-1] || !down && nums[i] > nums[i-1]){
                    swap(nums, i, i-1);
            }
            
            down = !down;
            
        }
        
        return;
    }
}
