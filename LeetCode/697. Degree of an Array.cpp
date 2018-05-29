class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, array<int, 3>> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]][0] = 1;
                mp[nums[i]][1] = mp[nums[i]][2] = i;
            }
            else {
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
        }
        int maxDegree = 0;
        int minLen = INT_MAX;
        for(auto p: mp) {
            if(p.second[0] > maxDegree) {
                maxDegree = p.second[0];
                minLen = p.second[2]-p.second[1]+1;
            }
            else if(p.second[0] == maxDegree) {
                minLen = min(minLen, p.second[2]-p.second[1]+1);
            }
        }
        return minLen;
    }
};