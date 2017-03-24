#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include"util.hpp"
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int> &prices) {

            int len = prices.size();

            if(0 == len)
                return 0;


            int lProfit[len];     
            int min = prices[0];
            lProfit[0]=0;

            for(int i = 1; i < len; i++){
                if(prices[i]-min > lProfit[i-1])
                    lProfit[i] = prices[i]-min;
                else
                    lProfit[i] = lProfit[i-1];

                if(prices[i]<min)
                    min = prices[i];

            }

            int rProfit[len];     
            int Max = prices[len-1];
            rProfit[len-1]=0;

            for(int i = len-1-1; i >= 0; i--){
                if(Max - prices[i] > rProfit[i+1])
                    rProfit[i] = Max - prices[i];
                else
                    rProfit[i] = rProfit[i+1];

                if(prices[i]>Max)
                    Max = prices[i];
            }

            int MaxProfit = 0;

            for(int i = 0; i < len-1; i++){

                MaxProfit = max(lProfit[i]+rProfit[i+1], MaxProfit);

            }

                MaxProfit = max(lProfit[len-1], MaxProfit);
                MaxProfit = max(rProfit[0], MaxProfit);
           

            return MaxProfit;
        }
};

class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        // two dp, the max ending with index i, the max starting with index i

        int len = prices.size();
        
        if(1 >= len)
            return 0;
        
        vector<int> dpEnd(len, -1);
        dpEnd[0] = 0;
        vector<int> dpBeg(len, -1);
        dpBeg[len -1 ] = 0;
        
        int v_min = prices[0];
        int v_max = prices[0];
        
        for(int i = 1; i !=len; ++i ){
            int p = prices[i];
            v_max = max(p, v_max);
            if(v_max > v_min)
                dpEnd[i] = max(dpEnd[i-1], v_max - v_min);
            else
                dpEnd[i] = dpEnd[i-1];    
            if(p < v_min){
                // minimun needs update;
                v_min = p;
                v_max = INT_MIN;
            }
        }
        
        v_min = prices[len-1];
        v_max = prices[len-1];
        
        for(int i = len -2; i >=0; --i ){
            int p = prices[i];
            v_min = min(p, v_min);
            if(v_max > v_min)
                dpBeg[i] = max(dpBeg[i+1], v_max - v_min);
            else
                dpBeg[i] = dpBeg[i+1];
            if(p > v_max){
                // minimun needs update;
                v_max = p;
                v_min = INT_MAX;
            }
        }
        /*
        */
        int maxProf = INT_MIN;
        for(int i = 0; i != len; ++i){
            int maxlr = max(dpEnd[i], dpBeg[i]);
            maxProf = max(maxProf, maxlr);
        }
        pVector(dpBeg);        
        pVector(dpEnd);        
        return maxProf;
    }
};


int main(){
vector<int> vec = {2,1,2,0,1};
Solution2 s;
cout <<s.maxProfit(vec) << endl;;
return 0;
}
