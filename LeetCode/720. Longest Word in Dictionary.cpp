class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        string res;
        dfs(words, "", 0, res);
        return res;
    }
    
    void dfs(vector<string>& words, string now, int index, string& res) {
        for(int i = index; i < words.size(); i++) {
            if(words[i].size() > now.size()+1) break;
            if(words[i].substr(0, now.size()) == now) {
                if(!cmp(words[i], res)) {
                    res = words[i];
                }
                dfs(words, words[i], i+1, res);
            }
        }
    }
    
    static bool cmp(string& a, string& b) {
        return a.size() < b.size() || (a.size() == b.size() && a > b);
    }
};