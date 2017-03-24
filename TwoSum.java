import java.util.*;

class pair{
    public int index;
    public int val;
    pair(int index, int val){
        this.index = index;
        this.val = val;
    }
}

public class TwoSum{
    public int[] twoSum(int[] nums, int target) {
        int len = nums.length;
        int[] res = new int[2];
        if(0 == len)
            return res;
            
        pair[] pArr = new pair[len];
        for(int i = 0; i < len; ++i){
            pArr[i] = new pair(i, nums[i]);
        }
        Arrays.sort(pArr, new Comparator<pair>()
                {
                public int compare(pair A, pair B){
                    return A.val - B.val;
                    }
                }
        );

        int i = 0;
        int j = len -1;
        while(i < j){
            if (pArr[i].val + pArr[j].val == target){
                res[0] = Math.min(pArr[i].index+1, pArr[j].index+1);
                res[1] = Math.max(pArr[i].index+1, pArr[j].index+1);
                return res;
            }
            else if ( pArr[i].val + pArr[j].val < target){
                ++i;
            }
            else{
                --j;
            }
        }
        return res;
    }

    public static void main(String[] args){
        TwoSum t = new TwoSum();
        int[] nums = new int[]{3, 2, 4};
        System.out.println(Arrays.toString(t.twoSum(nums, 6)));
    }
}
