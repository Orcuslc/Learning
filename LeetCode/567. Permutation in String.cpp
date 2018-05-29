class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        int target[26]; memset(target, 0, sizeof(target));
        for(char c: s1) target[c-'a']++;
        
        for(int i = 0; i < s1.size(); i++) target[s2[i]-'a']--;
        if(isEqual(target)) return true;
        
        for(int i = s1.size(); i < s2.size(); i++) {
            target[s2[i]-'a']--;
            target[s2[i-s1.size()]-'a']++;
            if(isEqual(target)) return true;
        }
        return false;
    }
    
    bool isEqual(int* t) {
        for(int i = 0; i < 26; i++) {
            if(t[i] != 0) return false;
        }
        return true;
    }
};