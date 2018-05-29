/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(!intervals.size()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int end = intervals[0].end, count = 1;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start >= end) {
                end = intervals[i].end;
                count++;
            }
        }
        return intervals.size()-count;
    }
    
    static bool cmp(Interval s1, Interval s2) {
        return s1.end < s2.end;
    }
};