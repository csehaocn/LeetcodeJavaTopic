public class MedianOfTwoSortedArray{
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int n = len1 + len2;
        // n == 4
        if( 0 == n % 2){
            System.out.println("test");
            int a = findKth(nums1, nums2, 0, 0, n/2);
            int b = findKth(nums1, nums2, 0, 0, n/2 + 1);
            System.out.println(a);
            System.out.println(b);
            return (findKth(nums1, nums2, 0, 0, n/2) + findKth(nums1, nums2, 0, 0, n/2 + 1) ) / 2.0;
        }
        // n == 5
        if( 1 == n % 2){
            return findKth(nums1, nums2, 0, 0, n/2+1);
        }
        
        return 0.0;
    }
    
    public int findKth(int[] nums1, int[] nums2, int index1, int index2, int k){
    
        // if k == 4
        // if k == 5

        int len1 = nums1.length - index1;
        int len2 = nums2.length - index2;
        
        if(len1 + len2 < k){
            return Integer.MIN_VALUE;
        }
        
        if(0 == len1)
            return nums2[index2 + k - 1];
        
        if(0 == len2)
            return nums1[index1 + k - 1];
        
        if(1 == k){
            return Math.min(nums1[0], nums2[0]);
        }
        
        if(2 == k)
            return Math.max(nums1[0], nums2[0]);
        
        // if 2 == k, kd2 = 1; 3 == k, kd2 = 1;
        
        int kd2 = k/2;
        if(len1 < kd2){
            return findKth(nums1, nums2, index1, index2 + kd2, k-kd2);
        }
        if(len2 < kd2){
            return findKth(nums1, nums2, index1 + kd2, index2, k-kd2);
        }
        
        int m1 = nums1[index1 + kd2 -1];
        int m2 = nums2[index2 + kd2 -1];
        
        // k = 4 kd2 = 2
        // k = 5 kd2 = 2
        if(m1 == m2){
            if(0 == k % 2)
                return m1;
            else
                {
                    return findKth(nums1, nums2, index1, index2 + kd2, k-kd2);
                }
        }
        
        if(m1 < m2)
            return findKth(nums1, nums2, index1 + kd2, index2, k-kd2);
        
        if(m1 > m2)
            return findKth(nums1, nums2, index1, index2 + kd2, k-kd2);
        
        return Integer.MIN_VALUE;
    }
    
    public static void main(String[] args){
        MedianOfTwoSortedArray m = new MedianOfTwoSortedArray();
        int[] nums1 = {1, 2};
        int[] nums2 = {1, 2};
        double res = m.findMedianSortedArrays(nums1, nums2);
        System.out.println(res);
    }
    
}
