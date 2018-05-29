class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<unordered_set<int> > in(numCourses), out(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(auto edge: prerequisites) {
            in[edge.first].insert(edge.second);
            out[edge.second].insert(edge.first);
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            indegree[i] = in[i].size();
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int now = q.front(); q.pop(); res.push_back(now);
            for(int n: out[now]) {
                indegree[n]--;
                if(indegree[n] == 0) q.push(n);
            }
        }
        
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] != 0) return vector<int>();
        }
        return res;
    }
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res(numCourses, 0), mark(numCourses, 0);
        vector<unordered_set<int> > graph(numCourses);
        int order = numCourses;
        for(auto edge: prerequisites) graph[edge.second].insert(edge.first);
        for(int i = 0; i < numCourses; i++) {
            if(!mark[i]) {
                if(!dfs(res, mark, graph, i, order)) return vector<int>();
            }
        }
        return res;
    }
    
    bool dfs(vector<int>& res, vector<int>& mark, vector<unordered_set<int> >& graph, int n, int& order) {
        mark[n] = -1;
        for(auto v: graph[n]) {
            if(mark[v] < 0) return false; // have circle;
            else if(!mark[v] && !dfs(res, mark, graph, v, order)) return false;
        }
        mark[n] = 1;
        res[--order] = n;
        return true;
    }
};