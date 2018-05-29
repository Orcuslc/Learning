class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int dp[nums.size()][nums.size()]; // subgame, between i and j;
        int presum[nums.size()+1] = {0};
        for(int i = 1; i <= nums.size(); i++) presum[i] = presum[i-1]+nums[i-1];
        for(int i = 0; i < nums.size(); i++) dp[i][i] = nums[i]; // init;
        for(int end = 1; end < nums.size(); end++) {
            for(int start = end-1; start >= 0; start--) {
                dp[start][end] = presum[end+1]-presum[start] - min(dp[start][end-1], dp[start+1][end]);
            }
        }
        return 2*dp[0][nums.size()-1] >= presum[nums.size()];
    }
};