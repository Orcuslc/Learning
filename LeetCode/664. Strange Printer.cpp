class Solution {
public:
    int strangePrinter(string s) {
        if(!s.size()) return 0;
        int dp[s.size()][s.size()];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for(int len = 1; len < s.size(); len++) {
            for(int start = 0; start+len < s.size(); start++) {
                int end = start+len;
                dp[start][end] = len+1;
                for(int k = start+1; k <= end; k++) {
                    int local = dp[start][k-1]+dp[k][end];
                    if(s[k-1] == s[end]) local--;
                    dp[start][end] = min(dp[start][end], local);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};