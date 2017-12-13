class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.size()+1]; 
        memset(dp, false, sizeof(dp)); dp[0] = true;
        // for(string word : wordDict) {
        //     for(int i = s.size(); i >= word.size(); i--) {
        //         dp[i] = dp[i] || (s.substr(i-word.size(), word.size()) == word? dp[i-word.size()] : false);
        //         cout << dp[i] << endl;
        //     }
        // }
        for(int i = 1; i <= s.size(); i++) {
            for(string word: wordDict) {
                dp[i] = dp[i] || (i >= word.size() && (dp[i-word.size()] && s.substr(i-word.size(), word.size()) == word)); 
            }
        }
        return dp[s.size()];
    }
};