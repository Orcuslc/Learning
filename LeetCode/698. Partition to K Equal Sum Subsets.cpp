class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0; 
        for(int i: nums) sum += i;
        if(sum % k != 0) return false;
        sum /= k;
        sort(nums.begin(), nums.end(), cmp);
        vector<int> vis(nums.size(), 0);
        return dfs(nums, vis, 0, sum, k, 0, 0);
    }
    
    bool dfs(vector<int>& nums, vector<int>& vis, int local, int sum, int k, int count, int index) {
        if(count == k-1) {
            return true;
        }
        if(local == sum) {
            return dfs(nums, vis, 0, sum, k, count+1, 0);
        }
        for(int i = index; i < nums.size(); i++) {
            if(vis[i]) continue;
            if(nums[i]+local <= sum) {
                vis[i] = 1;
                bool nxt = dfs(nums, vis, local+nums[i], sum, k, count, i+1);
                vis[i] = 0;
                if(nxt) return true;
            }
        }
        return false;
    }
    
    static bool cmp(int x, int y) {
        return x > y;
    }
};