/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    
    class IntervalComp implements Comparator<Interval>{
        public int compare(Interval x, Interval y){ return x.start - y.start; }
    }
    
    public boolean canAttendMeetings(Interval[] intervals) {
        int len = intervals.length;
        if(0 == len)
            return true;
        
        Arrays.sort(intervals, new IntervalComp());
        
        for(int i = 1; i!= len; ++i){
            if(intervals[i].start < intervals[i-1].end)
                return false;
        }
        
        return true;
        
    }
}
