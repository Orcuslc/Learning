class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int> > mp;
        int res = s.size();
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].first++;
            mp[s[i]].second = i;
        }
        for(auto p: mp) {
            if(p.second.first == 1) res = min(res, p.second.second);
        } 
        return res == s.size()? -1: res;
    }
};