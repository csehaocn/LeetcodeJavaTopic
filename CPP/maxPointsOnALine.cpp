/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int vLen = points.size();
        
        
        int maxNumPoints = 0;
        
        //Iterate all points
        for(int i = 0; i != vLen; ++i){
            
            unordered_map<double, int> kCount;
            int upstraightCount = 0;
            //Count the numer of ks for the same K;
            
            int overlapWithI = 0;
            
            //Iterate through the right points for i
            //Maximum will be caputured by the smallest indexed point on the straight line.
            for(int j = i+1; j != vLen; ++j)
            {
                    // Count the k and put into the map
                    Point* pPi = &points[i];
                    Point* pPj = &points[j];
                    
                    if(pPi->x == pPj->x){
                        pPi->y == pPj->y?++overlapWithI:++upstraightCount;
                    }
                    else{
                        // k = y1 - y2 / x1 - x2 
                        //Noice: notice how the double makes effect here, without double ....
                        double k = double(pPi->y-pPj->y)/double(pPi->x-pPj->x);
                        kCount.find(k) == kCount.end()?kCount[k]=1:kCount[k]++;
                    }
            }
            //Starts with the upstraightCount then the rest of the Ks.
            int maxNumWithI = upstraightCount;
            for(unordered_map<double, int>::iterator mIter = kCount.begin(); mIter !=kCount.end(); ++mIter){
                maxNumWithI = max(maxNumWithI, mIter->second);
            }
            //Plus the points overlap with I, it goes through all possible lines.
            maxNumWithI += overlapWithI;
            maxNumWithI += 1;
            // ... 
            
            maxNumPoints = max(maxNumPoints, maxNumWithI);
            
        }
        
        return maxNumPoints;
    }
};
