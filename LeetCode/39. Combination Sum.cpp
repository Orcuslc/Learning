class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res; vector<int> now;
        dfs(res, now, candidates, 0, 0, target);
        return res;
    }
    
    void dfs(vector<vector<int> >& res, vector<int>& now, vector<int>& candidates, int sum, int index, int target) {
        if(sum == target) {
            res.push_back(now);
            return;
        }
        for(int j = index; j < candidates.size(); j++) {
            if(sum + candidates[j] <= target) {
                now.push_back(candidates[j]);
                dfs(res, now, candidates, sum+candidates[j], j, target);
                now.pop_back();
            }
            else break;
        }
    }
};