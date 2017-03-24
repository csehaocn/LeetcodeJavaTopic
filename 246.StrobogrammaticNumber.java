public class Solution {
    public boolean isStrobogrammatic(String num) {
        int len = num.length();
        if(0 == len)
            return true;
        int i = 0;
        int j = len-1;
        char[] nums = num.toCharArray();
        while(i <= j){
            if('1' == nums[i] && '1' == nums[j] || '8' == nums[i] && '8' == nums[j] || '6' == nums[i] && '9' == nums[j] || '9' == nums[i] && '6' == nums[j] || '0' == nums[i] && '0' == nums[j]){
                i++;
                j--;
            }else
                return false;
                
        }
        
        return true;
    }
}
