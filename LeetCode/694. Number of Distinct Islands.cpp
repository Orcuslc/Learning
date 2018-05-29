class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int count = 0; 
        vector<vector<pair<int, int>>> s;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                vector<pair<int, int>> local;
                if(grid[i][j] == 1) {
                    dfs(grid, local, i, j, i, j);
//                     sort(local.begin(), local.end(), cmp);
//                     bool flag = true;
//                     for(auto v: s) {
//                         if(isEqual(v, local)) {
//                             flag = false;
//                             break;
//                         }
                    
//                     cout << flag << endl;
//                     if(flag) {
//                         s.push_back(local);
//                         count++;
//                     }
                    if(find(s.begin(), s.end(), local) == s.end()) {
                        s.push_back(local);
                        count++;
                    }
                } 
                // if(find(s.begin(), s.end(), local) == s.end()) {
                //     s.push_back(local);
                //     count++;
                // }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& grid, vector<pair<int, int>>& local, int i, int j, int i0, int j0) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return;
        local.push_back(make_pair(i-i0, j-j0));
        grid[i][j] = 0;
        dfs(grid, local, i-1, j, i0, j0);
        dfs(grid, local, i+1, j, i0, j0);
        dfs(grid, local, i, j-1, i0, j0);
        dfs(grid, local, i, j+1, i0, j0);
    }
    
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first || (a.first == b.first && a.second > b.second);
    }
    
    bool isEqual(vector<pair<int, int>>& a, vector<pair<int, int>>& b) {
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); i++) {
            cout << a[i].first << b[i].first << endl;
            cout << a[i].second << b[i].second << endl;
            if(a[i].first != b[i].first || a[i].second != b[i].second) {
                return false;
            }
        }
        return true;
    }
};