class Solution {
public:
    int findMin(vector<int> &num) {
        int len = num.size();

        int l = 0;
        int u = len - 1;
        int m = (u+l)/2;
        
        while(u-l > 1){
            if(num[m] > num[u])
                l = m+1;
            else
                u = m;
            m = (u+l)/2;
        }
        
        if(num[u]> num[l])
            return num[l];
        else
            return num[u];
        
    }
};


