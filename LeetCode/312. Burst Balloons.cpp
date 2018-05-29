class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int dp[nums.size()][nums.size()]; // subgame between i and j;
        memset(dp, 0, sizeof(dp));
        
        for(int len = 1; len <= n; len++) {
            for(int start = 1; start <= n-len+1; start++) {
                int end = start+len-1;
                int local = 0, maxLocal = 0;
                for(int i = start; i <= end; i++) { // ending with i, then nums[i-1]*nums[i]*nums[i+1] won't exist;
                    // so we can seperate the subgame into two subsubgames;
                    local = dp[start][i-1] + dp[i+1][end] + nums[start-1]*nums[end+1]*nums[i];
                    if(local > maxLocal) maxLocal = local;
                }
                dp[start][end] = maxLocal;
            }
        }
        return dp[1][n];
    }
};