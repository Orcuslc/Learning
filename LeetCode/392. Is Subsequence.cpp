class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(j < t.size()) {
            i += t[j++] == s[i];
        }
        return i >= s.size();
    }
};