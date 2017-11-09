class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        int count[26] = {0};
        for(char c: s1) {
            count[c-'a']++;
        }
        for(char c: s2) {
            count[c-'a']--;
            if(count[c-'a'] < 0) return false;
        }
        for(int i = 1; i < s1.size(); i++) {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0, i), s2.substr(s1.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s1.size()-i)))
                return true;
        }
        return false;
    }
};