class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res; vector<int> now;
        dfs(nums, res, now, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<vector<int> >&res, vector<int>& now, int begin) {
        res.push_back(now);
        for(int i = begin; i < nums.size(); i++) {
            now.push_back(nums[i]);
            dfs(nums, res, now, i+1);
            now.pop_back();
        }
    }
};