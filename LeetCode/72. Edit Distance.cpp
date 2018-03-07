class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.size()+1][word2.size()+1] = {0};
        for(int i = 0; i <= word1.size(); i++) {
            for(int j = 0; j <= word2.size(); j++) {
                dp[i][j] = (i*j == 0? (i == 0? j:i) : (word1[i-1] == word2[j-1]? dp[i-1][j-1] : min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1))));
            }
        }
        return dp[word1.size()][word2.size()];
    }
            
};