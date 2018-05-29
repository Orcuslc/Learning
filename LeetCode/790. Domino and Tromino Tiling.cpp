class Solution {
public:
    int numTilings(int N) {
        long dp[N+1] = {0};
        if(N == 1) {
            return 1;
        }
        else if(N == 2) {
            return 2;
        }
        else if(N == 3) {
            return 5;
        }
        dp[1] = 1; dp[2] = 2; dp[3] = 5;
        for(int i = 4; i <= N; i++) {
            dp[i] = (2*dp[i-1]+dp[i-3])%(1000000007);
        }
        return dp[N];
    }
};