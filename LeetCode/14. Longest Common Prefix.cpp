class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string dp = strs[0];
        int len = dp.length();
        for(int i = 1; i < strs.size(); i++) {
            for(int j = 0; j < len; j++) {
                if(dp[j] != strs[i][j]) {
                    dp = dp.substr(0, j);
                    len = j;
                    continue;
                }
            }
        }
        return dp;
    }
};