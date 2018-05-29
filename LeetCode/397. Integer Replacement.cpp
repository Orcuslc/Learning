class Solution {
public:
    int integerReplacement(int n) {
        int dp[n+1]; dp[0] = 1; dp[1] = 0;
        for(int i = 2; i <= n; i++) {
            if(n & 1) dp[i] = min(dp[i-1], dp[(i+1)/2]+1)+1;
            else dp[i] = dp[i>>1]+1;
        }
        return dp[n];
    }
};

class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        recursion(n, res);
        return res;
    }
    
    void recursion(int n, int& res) {
        if(n == 1) return;
        else if(n == 3) {
            res += 2;
            return;
        }
        else if(n == INT_MAX) {
            res = 32;
            return;
        }
        else {
            res++;
            if(n & 1) {
                if((n+1)%4 == 0) recursion(n+1, res);
                else recursion(n-1, res);
            }
            else recursion(n/2, res);
        }
    }
};