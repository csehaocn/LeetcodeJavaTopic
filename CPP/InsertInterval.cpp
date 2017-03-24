/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 

bool comp(const Interval &a, const Interval &b){
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        
        vector<Interval> res;
        //sort(intervals.begin(), intervals.end(), comp);
        int len = intervals.size();
        int l = newInterval.start;
        int r = newInterval.end;
        
        if(0 == len)
        {
            res.push_back(newInterval);
            return res;
        }

        for(int i = 0; i!=len; ++i)
        {
            Interval inter = intervals[i];
            if(inter.end < l)
            {
                res.push_back(inter);
            }
            else if(inter.start > r)
            {   
                res.push_back(inter);
            }
            else
            {
                l = min(inter.start, l);
                r = max(inter.end, r);
            }
        }
        
        res.push_back(Interval(l,r));
        sort(res.begin(), res.end(), comp);

        return res;
    }
};

