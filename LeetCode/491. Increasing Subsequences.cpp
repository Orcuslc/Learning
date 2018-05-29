class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> now;
        dfs(nums, res, now, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int> now, int n) {
        if(now.size() >= 2) res.push_back(now);
        unordered_map<int, int> used;
        for(int i = n; i < nums.size(); i++) {
            if(used[nums[i]]) continue;
            if(now.size() == 0 || now.back() <= nums[i]) {
                used[nums[i]] = 1;
                now.push_back(nums[i]);
                dfs(nums, res, now, i+1);
                now.pop_back();
            }
        }
    } 
};