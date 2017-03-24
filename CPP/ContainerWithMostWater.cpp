class Solution {
    public:

        int maxArea(vector<int> &height) {

            int vol = 0;
            vector<int>::iterator i = height.begin();
            vector<int>::iterator j = height.end();
            while(j!=i){
                vol = max(vol,int(j-i-1)*min(*i,*(j-1)));
                if(*i>*(j-1)){
                    j--;
                }else{
                    i++;
                }
            }
            return vol;
        }
};
