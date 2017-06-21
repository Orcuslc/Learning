class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int dp = 0;
        unordered_map<int, int> mp; // mp存储了包含i的最大序列长度
        for(int i : nums) {
            if(mp[i]) continue; // Repeated;
            mp[i] = mp[i-1]+mp[i+1]+1;
            dp = max(dp, mp[i]);
            mp[i-mp[i-1]] = mp[i+mp[i+1]] = mp[i]; // update the endpoints;
        }
        return dp;
    }
};