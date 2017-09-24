class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res; vector<string> now;
        dfs(res, now, s, 0);
        return res;
    }
    
    void dfs(vector<vector<string> >& res, vector<string>& now, string& s, int start) {
        if(start == s.size()) {
            res.push_back(now);
            return;
        }
        for(int end = s.size()-1; end >= start; end--) {
            if(isPalindrome(s, start, end)) {
                now.push_back(s.substr(start, end-start+1));
                dfs(res, now, s, end+1);
                now.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};