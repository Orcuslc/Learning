class Solution {
public:
    int findIntegers(int num) {
        int dp[32];
        dp[0] = 1; dp[1] = 2;
        for(int i = 2; i < 32; i++) dp[i] = dp[i-1]+dp[i-2];
        int res = 0, mask = 30, flag = 0;
        while(mask >= 0) {
            if(num & (1<<mask)) {
                res += dp[mask];
                if(flag) return res;
                flag = 1;
            }
            else flag = 0;
            mask--;
        }
        return res+1;
    }
};