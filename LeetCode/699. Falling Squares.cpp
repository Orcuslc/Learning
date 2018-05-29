class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<int> res(positions.size()+1, 0);
        unordered_map<int, int> mp;
        int maxHeight = 0;
        for(int i = 0; i < positions.size(); i++) {
            int left = positions[i].first, height = positions[i].second;
            int maxLocalHeight = 0, flag = false, LocalLeft = left;
            for(int i = left; i < left+height; i++) {
                if(mp.find(i) != mp.end()) {
                    flag = true;
                    if(mp[i] > maxLocalHeight) {
                        maxLocalHeight = mp[i];
                        LocalLeft = i;
                    }
                }
            }
            if(!flag) {
                for(int i = left; i < left+height; i++) {
                    mp[i] = height;
                }
                maxLocalHeight = height;
            }
            else {
                for(int i = left; i < left+height; i++) {
                    mp[i] = maxLocalHeight+height;
                }
                maxLocalHeight += height;
            }
            res[i+1] = max(res[i], maxLocalHeight);
        }
        res.erase(res.begin());
        return res;
    }
};