class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res; vector<int> now;
        dfs(res, now, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int> >& res, vector<int>& now, vector<int>& nums, int i) {
        res.push_back(now);
        for(int j = i; j < nums.size(); j++) {
            if(j == i || nums[j] != nums[j-1]) {
                now.push_back(nums[j]);
                dfs(res, now, nums, j+1);
                now.pop_back();
            }
        }
    }
};