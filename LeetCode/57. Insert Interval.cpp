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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(!intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int left = 0, right = intervals.size()-1;
        while(left <= intervals.size()-1) {
            if(intervals[left].end >= newInterval.start) break;
            left++;
        }
        while(right >= 0) {
            if(intervals[right].start <= newInterval.end) break;
            right--;
        }
        if(left - right == 1) { // Not overlap;
            intervals.insert(intervals.begin()+left, newInterval);
            return intervals;
        }
        // left < right
        int newstart, newend;
        if(newInterval.start < intervals[left].start) newstart = newInterval.start;
        else newstart = intervals[left].start;
        if(newInterval.end > intervals[right].end) newend = newInterval.end;
        else newend = intervals[right].end;
        intervals.erase(intervals.begin()+left, intervals.begin()+right+1);
        intervals.insert(intervals.begin()+left, Interval(newstart, newend));
        return intervals;
    }
    
};