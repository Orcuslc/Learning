class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0, sum = 0;
        dfs(nums, res, sum, S, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, int& res, int sum, int S, int n) {
        if(n == nums.size()) {
            if(sum == S) res++;
            return;
        };
        
        dfs(nums, res, sum+nums[n], S, n+1);
        dfs(nums, res, sum-nums[n], S, n+1);
    }
};

