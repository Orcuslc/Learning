class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(!points.size()) return 0;
        sort(points.begin(), points.end(), cmp);
        int pos = points[0].second;
        int count = 1;
        for(int i = 1; i < points.size(); i++) {
            if(pos >= points[i].first) continue;
            count++;
            pos = points[i].second;
        }
        return count;
    }
    
    static bool cmp(pair<int, int> A, pair<int, int> B) {
        return A.second < B.second;
    }
};