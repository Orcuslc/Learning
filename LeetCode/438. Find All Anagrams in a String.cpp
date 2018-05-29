class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sv[26] = {0}, pv[26] = {0};
        if(!p.size() || !s.size() || s.size() < p.size()) return vector<int>();
        for(int i = 0; i < p.size(); i++) {
            sv[s[i]-'a']++; pv[p[i]-'a']++;
        }
        vector<int> res;
        if(equal(sv, pv)) res.push_back(0);
        for(int i = p.size(); i < s.size(); i++) {
            sv[s[i]-'a']++; sv[s[i-p.size()]-'a']--;
            if(equal(sv, pv)) res.push_back(i-p.size()+1);
        }
        return res;
    }
    
    bool equal(int* s, int* p) {
        for(int i = 0; i < 26; i++) {
            if(s[i] != p[i]) return false;
        }
        return true;
    }
};