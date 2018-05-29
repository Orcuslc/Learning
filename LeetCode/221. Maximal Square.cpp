class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        int maxlen = 0;
        int dp[matrix.size()][matrix[0].size()]; 
        // dp[i][j] represents max square size with the right-down vertex  
        for(int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxlen = max(maxlen, dp[i][0]);
        }
        for(int j = 0; j < matrix[0].size(); j++) {
            dp[0][j] = matrix[0][j] - '0';
            maxlen = max(maxlen, dp[0][j]);
        }
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                dp[i][j] = matrix[i][j] == '1'? min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1 : 0;
                maxlen = max(maxlen, dp[i][j]);
            }
        }
        return maxlen*maxlen;
    }
};