class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<pair<string, double>>> mp;
        for(int i = 0; i < equations.size(); i++) {
            auto p = equations[i];
            if(mp.find(p.first) == mp.end()) mp[p.first] = vector<pair<string, double>>();
            if(mp.find(p.second) == mp.end()) mp[p.second] = vector<pair<string, double>>();
            mp[p.first].push_back(make_pair(p.second, values[i]));
            mp[p.second].push_back(make_pair(p.first, 1/values[i]));
        }
        
        vector<double> res(queries.size(), 0.0);
        for(int i = 0; i < queries.size(); i++) {
            unordered_set<string> st;
            res[i] = dfs(mp, st, queries[i].first, queries[i].second, 1.0);
            if(res[i] == 0.0) res[i] = -1.0;
        }
        return res;
    }
    
    double dfs(unordered_map<string, vector<pair<string, double>>>& mp, unordered_set<string>& vis, string a, string b, double val) {
        if(vis.find(a) != vis.end()) return 0.0;
        if(mp.find(a) == mp.end()) return 0.0;
        if(a == b) return val;
        vis.insert(a);
        
        vector<pair<string, double>> cur = mp[a];
        double tmp = 0.0;
        for(auto p: cur) {
            tmp = dfs(mp, vis, p.first, b, val*p.second);
            if(tmp != 0.0) break;
        }
        vis.erase(a);
        return tmp;
    }
};