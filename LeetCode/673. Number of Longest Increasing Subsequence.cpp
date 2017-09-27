class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), count(nums.size(), 1);
        int maxLen = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = i-1; j >= 0; j--) {
                if(nums[i] > nums[j]) {
                    if(dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[j]+1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(dp[i] == maxLen) res += count[i];
        }
        return res;
    }
};