class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int> > s; vector<int> res(n, 0);
        for(string log: logs) {
            int pos1 = log.find(':', 0);
            int pos2 = log.find(':', pos1+1);
            string names = log.substr(0, pos1);
            string start = log.substr(pos1+1, pos2-pos1-1);
            string times = log.substr(pos2+1);
            int name = stoi(names), time = stoi(times);
            if(start == "start") s.push(pair<int, int>(name, time));
            else {
                pair<int, int> p = s.top(); s.pop();
                res[p.first] += time - p.second + 1;
                if(!s.empty()) res[s.top().first] -= time-p.second+1;
            }
        }
        return res;
    }
};