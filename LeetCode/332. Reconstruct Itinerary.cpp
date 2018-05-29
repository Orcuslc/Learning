class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string> > graph;
        unordered_map<string, unordered_map<string, int> > vis;
        for(auto p: tickets) graph[p.first].insert(p.second);
        
        // for(auto p: graph) vis[p.first] = unordered_set<string>();
        for(auto p: graph) for(auto n: p.second) vis[p.first][n]++;
        
        vector<string> s;
        euler(graph, vis, s, "JFK"); s.push_back("JFK");
        vector<string> res(s.rbegin(), s.rend());
        return res;
    }
    
    void euler(unordered_map<string, multiset<string> >& graph, unordered_map<string, unordered_map<string, int> >& vis, vector<string>& res, string u) {
        for(auto v: graph[u]) {
            if(vis[u][v]) {
                vis[u][v]--;
                euler(graph, vis, res, v);
                res.push_back(v);
            }
        }
    }
};