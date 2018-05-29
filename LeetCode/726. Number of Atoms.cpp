class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<string, int> count;
        stack<unordered_map<string, int>> s;
        for(int i = 0; i < formula.size(); i++) {
            if(formula[i] == '(') {
                unordered_map<string, int> t;
                s.push(t);
            }
            else if(formula[i] >= 'A' && formula[i] <= 'Z') {
                if(i == formula.size()-1) count[string(1, formula[i])]++;
                else if(formula[i+1] >= 'a' && formula[i+1] <= 'z') {
                    string stmp = formula.substr(i, 2);
                    i++;
                    if(formula[i+1] >= '0' && formula[i+1] <= '9') {
                        i++;
                        int num = formula[i]-'0';
                        while(i+1 < formula.size() && formula[i+1] >= '0' && formula[i+1] <= '9') {
                            i++;
                            num = num*10 + formula[i] - '0';
                        }
                        if(s.empty()) count[stmp] += num;
                        else s.top()[stmp] += num;
                    }
                    else {
                        if(s.empty()) count[stmp]++;
                        else s.top()[stmp]++;
                    }
                }
                else if((formula[i+1] >= 'A' && formula[i+1] <= 'Z') || formula[i+1] == '(' || formula[i+1] == ')') {
                    if(s.empty()) count[string(1, formula[i])]++;
                    else s.top()[string(1, formula[i])]++;
                }
                else if(formula[i+1] >= '0' && formula[i+1] <= '9') {
                    char c = formula[i];
                    i++;
                    int num = formula[i]-'0';
                    while(i+1 < formula.size() && formula[i+1] >= '0' && formula[i+1] <= '9') {
                        i++;
                        num = num*10 + formula[i] - '0';
                    }
                    if(s.empty()) count[string(1, c)] += num;
                    else s.top()[string(1, c)] += num;
                }
            }
            else if(formula[i] == ')') {
                auto p = s.top(); s.pop();
                if(i+1 < formula.size() && formula[i+1] >= '0' && formula[i+1] <= '9') {
                    i++;
                    int num = formula[i]-'0';
                    while(i+1 < formula.size() && formula[i+1] >= '0' && formula[i+1] <= '9') {
                        i++;
                        num = num*10 + formula[i] - '0';
                    }
                    if(s.empty()) {
                        for(auto q: p) {
                            count[q.first] += q.second*num;
                        }
                    }
                    else {
                        for(auto q: p) {
                            s.top()[q.first] += q.second*num;
                        }
                    }
                }
            }
        }
        string res = "";
        vector<pair<string, int>> v;
        for(auto p: count) {
            v.emplace_back(p.first, p.second);
        }
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < v.size(); i++) {
            res += v[i].first;
            if(v[i].second > 1) res += to_string(v[i].second);
        }
        return res;
    }
    
    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        return a.first < b.first;
    }
};