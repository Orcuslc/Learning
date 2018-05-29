class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, local = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                local = 0;
                if(grid[i][j] == 1) dfs(grid, i, j, local);
                maxArea = max(maxArea, local);
            }
        }
        return maxArea;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& maxArea) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return;
        maxArea++;
        grid[i][j] = 0;
        dfs(grid, i-1, j, maxArea);
        dfs(grid, i+1, j, maxArea);
        dfs(grid, i, j-1, maxArea);
        dfs(grid, i, j+1, maxArea);
    }
};