class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int n : nums) sum += n;
        if(sum % 2 != 0) return false;
        vector<int> sub; bool res = false;
        dfs(nums, sub, 0, 0, sum/2, res);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& sub, int index, int sum, int target, bool& res) {
        if(sum == target) {
            res = true;
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            if(sum + nums[i] > target) break;
            sub.push_back(nums[i]);
            dfs(nums, sub, i+1, sum+nums[i], target, res);
            sub.pop_back();
        }
    }
};