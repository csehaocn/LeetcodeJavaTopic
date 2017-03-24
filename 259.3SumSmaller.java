public class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        
        int len = nums.length;
        if(0 == len)
            return 0;
        Arrays.sort(nums);
        int res = 0;
        
        for(int i = 0; i < len-2; ++i){
            int l = i+1; 
            int r = len-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum >= target){
                    r--;
                }else{
                    // Error: res += r - l + 1;
                    // The counting of possibilities should not involved in l itself.
                    res += r - l;
                    l++;
                }
            }
        }
        
        return res;
        // Brute Force can pass OJ
        /*
        int len = nums.length;
        if(0 == len)
            return 0;
        Arrays.sort(nums);
        int res = 0; 
        for(int i = 0; i != len; ++i)
            for(int j = i+1; j != len; ++j){
                int k = target - nums[i] - nums[j];
                int s = j+1;
                while(s < len && nums[s++] < k)
                    res++;
        }
        
        return res;
        */
    }
}
