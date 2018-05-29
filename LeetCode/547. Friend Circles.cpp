class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
        vector<int> vis(M.size(), 0);
        for(int i = 0; i < M.size(); i++) {
            if(!vis[i]) {
                dfs(M, vis, i);
                res++;
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& M, vector<int>& vis, int i) {
        for(int j = 0; j < M.size(); j++) {
            if(!vis[j] && M[i][j]) {
                vis[j] = 1;
                dfs(M, vis, j);
            }
        }
    }
};