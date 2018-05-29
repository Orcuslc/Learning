class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> degree(n, 0);
        vector<int> res;
        vector<unordered_set<int> > graph(n);
        
        for(auto e: edges) { // Build graph
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        for(int i = 0; i < n; i++) degree[i] = graph[i].size();
        for(int remain = n; remain > 2;) {
            vector<int> to_del;
            for(int i = 0; i < n; i++) {
                if(degree[i] == 1) {
                    remain--;
                    to_del.push_back(i);
                    degree[i] = -1;
                }
            }
            for(auto i: to_del) {
                for(auto node: graph[i]) degree[node]--;
            }
        }
        for(int i = 0; i < n; i++) if(degree[i] >= 0) res.push_back(i);
        return res;
    }
};