class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int> > out(numCourses), in(numCourses);
        for(auto n: prerequisites) { // Construct the graph;
            out[n.second].insert(n.first);
            in[n.first].insert(n.second);
        }
        
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            indegree[i] = in[i].size();
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int now = q.front(); q.pop();
            for(auto n: out[now]) {
                indegree[n]--;
                if(indegree[n] == 0) q.push(n);
            }
        }
        for(int i: indegree) {
            if(i != 0) return false;
        }
        return true;
    }
};

