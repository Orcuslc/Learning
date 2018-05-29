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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> mp;
        vector<int> res;
        for(int i = 0; i < intervals.size(); i++) mp[intervals[i].start] = i;
        for(Interval interval : intervals) {
            auto low = mp.lower_bound(interval.end);
            if(low == mp.end()) res.push_back(-1);
            else res.push_back(low->second);
        }
        return res;
    }
};