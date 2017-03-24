public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = new int[2];
        int len = numbers.length;
        int i = 0; 
        int j = len-1;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                res[0] = i+1;
                res[1] = j+1;
                break;
            }else if(sum > target){
                j--;
            }else{
                i++;
            }
        }
        
        return res;
    }
}
