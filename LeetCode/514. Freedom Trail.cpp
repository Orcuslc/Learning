class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int dp[key.size()+1][ring.size()]; memset(dp, 0, sizeof(dp));
        for(int i = key.size()-1; i >= 0; i--) {
            for(int j = 0; j < ring.size(); j++) {
                dp[i][j] = INT_MAX;
                for(int k = 0; k < ring.size(); k++) {
                    if(ring[k] == key[i]) {
                        int diff = abs(j-k);
                        dp[i][j] = min(dp[i][j], min(diff, (int)ring.size()-diff)+dp[i+1][k]);
                    }
                }
            }
        }
        return dp[0][0]+key.size();
    }
};