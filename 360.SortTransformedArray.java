public class Solution {
    
    public int transform(int x, int a, int b, int c){
        return x*(a*x+b) + c;
    }
    
    public void reverse(int[] a){
        int i = 0; 
        int j = a.length-1;
        while(i < j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
        return;
    }
    
    public int[] sortTransformedArray(int[] nums, int a, int b, int c){
        int len = nums.length;
        int[] res = new int[len];
        if(0 == len)
            return res;
        int sign = a >= 0 ? 1 : -1;
        if(0 == a){
            for(int i = 0; i != len; ++i){
                // Error: transform(i, a, b, c);
                res[i] = transform(nums[i], a, b, c);
            }
        }else{
            double m = (double)b / (2 * (double)a) * -1;
            //System.out.println(m);
            int x = 0; 
            int y = len-1;
            int k = 0;
            while(x <= y){
                //double xx = (y - m)*sign;
                //double yy = (m - x)*sign;
                //System.out.println("" + xx + " " + yy);
                // Error: (y - m) * sign < (m - x) * sign
                // Error: shouldn't add any sign here..., the further away from m, the larger (smaller)
                if( (nums[y] - m) < (m - nums[x]) ){
                    res[k++] = transform(nums[x++], a, b, c);
                }else{
                    res[k++] = transform(nums[y--], a, b, c);
                }    
            }
        }
        
        if(0 == a && b < 0){
            reverse(res);
        }
        
        if(a > 0){
            reverse(res);
        }
        
        return res;
        
    }
    
    /* Start from the middle, actually, starts from two sides are easier.
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int len = nums.length;
        int[] res = new int[len];
        if(0 == len)
            return res;
        
        double m = (double)b / (2 * (double)a) * -1;
        int j = 0;
        while(j != nums.length && nums[j] < m){
            j++;
        }
        int i = j-1;
        
        //System.out.println(len);
        
        // Error: typo... i != len
        // This is a serious problem, get used to use i as index too much.
        for(int k = 0; k != len; ++k){
            //System.out.println("k = " + k + " " + i + " "+ j);
            if(j >= len){
                //System.out.println("" + i + " "+ j);
                res[k] = transform(nums[i--], a, b, c);
                // Error: array out of bound
                // Forgot continue here.
                continue;
            }
            if(i < 0){
                res[k] = transform(nums[j++], a, b, c);
                continue;
            }
                
            if( ((double)j - m)*(double)a > (m - (double)i)*(double)a ){
                res[k] = transform(nums[i--], a, b, c);
            }else{
                res[k] = transform(nums[j++], a, b, c);
            }
        }
        
        return res;
        
    }
    */
}
