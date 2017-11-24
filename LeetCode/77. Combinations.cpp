class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(res, vector<int>(), n, k);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int> now, int i, int k) {
        if(k == 0) {
            res.push_back(now);
            return;
        }
        if(i <= 0) return;
        
        now.push_back(i);
        dfs(res, now, i-1, k-1);
        now.pop_back();
        dfs(res, now, i-1, k);
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        dfs(res, vector<int>(), n, k, 1);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int> now, int n, int k, int start) {
        if(k == 0) {
            res.push_back(now);
            return;
        } 
        
        for(int i = start; i <= n-k+1; i++) {
            now.push_back(i);
            dfs(res, now, n, k-1, i+1);
            now.pop_back();
        }
    }
};