public class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> ret = new ArrayList<String>();
        int len = nums.length;
        if(0 == len){
            if(lower == upper){
                ret.add("" + lower);
            }else{
                ret.add("" + lower + "->" + upper);
            }
            return ret;
        }
            
        int l = lower;
        int r = upper;
        for(int i = 0; i <= len; ++i){
            r = (i == len ? upper : nums[i] - 1);
            if(l == r){
                ret.add("" + l);
            }else if(r > l){
                ret.add("" + l + "->" + r);
            }
            // Error: forgot i == len
            if(i != len)
                l = nums[i]+1;
        }
        
        return ret;
    }
}
