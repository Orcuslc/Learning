class Solution {
public:
    int numDecodings(string s) {
        if(!s.size()) return 0;
        int dp[s.size()+1]; memset(dp, 0, sizeof(dp));
        dp[0] = 1; dp[1] = s[0] != '0'? 1:0;
        for(int i = 2; i <= s.size(); i++) {
            int one = stoi(s.substr(i-1, 1)), two = stoi(s.substr(i-2, 2));
            if(one >= 1 && one <= 9) dp[i] += dp[i-1];
            if(two >= 10 && two <= 26) dp[i] += dp[i-2];
        }
        return dp[s.size()];
    }
};