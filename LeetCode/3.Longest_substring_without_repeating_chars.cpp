class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dp = 0, start = 0;
        vector<int> map(256, -1);
        for(int i = 0; i < s.length(); i++) {
            start = max(map[s[i]]+1, start);
            map[s[i]] = i;
            dp = max(dp, i-start+1);
        }
        return dp;
    }
};