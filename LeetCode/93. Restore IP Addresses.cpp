class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(res, s, "", 0, 0);
        return res;
    }
    
    void dfs(vector<string>& res, string& s, string now, int count, int index) {
        if(index == s.size() && count == 4) {
            res.push_back(now);
            return;
        }
        if(count > 4) return;
        for(int i = 1; i <= 3; i++) {
            // cout << i << ' ' << index << endl;
            if(index + i > s.size()) return;
            if(s[index] == '0' && i >= 2) return;
            // cout << i << ' ' << index << ' ' << s.substr(index, i) << endl;
            if(i == 3 && stoi(s.substr(index, i)) < 256 || i < 3) {
                if(count == 3) dfs(res, s, now+s.substr(index, i), count+1, index+i);
                else dfs(res, s, now+s.substr(index, i)+'.', count+1, index+i);
            }
        }
    }
    
};