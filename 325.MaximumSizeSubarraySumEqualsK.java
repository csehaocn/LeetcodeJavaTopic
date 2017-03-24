public class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        int len = nums.length;
        if(0 == len)
            return 0;
        
        int sum = 0;
        Map<Integer, Integer> m = new HashMap<>();
        // Error: must consider the case where sum == k
        m.put(0, -1);
        int res = 0;
        
        for(int i = 0; i != len; ++i){
            sum += nums[i];
            if(!m.containsKey(sum)){
                m.put(sum, i);
            }
            //System.out.println(sum);
            // Error: k - sum ...
            if(m.containsKey(sum - k)){
                int dist = i - m.get(sum - k);
                res = Math.max(res, dist);
            }
        }
        
        return res;
    }
}
