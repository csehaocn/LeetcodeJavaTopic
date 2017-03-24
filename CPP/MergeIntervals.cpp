#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};



bool comp(const Interval &a, const Interval &b){
    return a.start < b.start;
}

class Solution {


    public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), comp);
        int len = intervals.size();
        if(0 == len)
        {
            return res;
        }

        int l = intervals[0].start;
        int r = intervals[0].end;

        for(int i = 0; i!=len-1; ++i)
        {
           if(r >= intervals[i+1].start) 
           {
                if(r < intervals[i+1].end){
                    r = intervals[i+1].end;
                }
           }
           else
           {
                res.push_back(Interval(l,r));
                l = intervals[i+1].start;
                r = intervals[i+1].end;
           }
        }

        res.push_back(Interval(l,r));

        return res;
    }
};


int main()
{
    vector<Interval> t;
    t.push_back(Interval(1,3));
    t.push_back(Interval(2,6));
    t.push_back(Interval(8,10));
    t.push_back(Interval(15,18));
    Solution S;
    t = S.merge(t);
    cout << t[0].start << t[0].end << endl;
    cout << t[1].start << t[1].end << endl;
    cout << t[2].start << t[2].end << endl;
    return 0;
}
