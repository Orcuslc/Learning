class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int dp[A.size()][B.size()] = {0};
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            dp[i][0] = (A[i] == B[0]);
        }
        for(int j = 0; j < B.size(); j++) {
            dp[0][j] = (A[0] == B[j]);
        }
        // dp[i][j]: max len of substrings ending with i, j;
        for(int i = 1; i < A.size(); i++) {
            for(int j = 1; j < B.size(); j++) {
                dp[i][j] = A[i] == B[j] ? dp[i-1][j-1]+1:0;
                // cout << i << " " << j << " " << dp[i][j] << endl;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};