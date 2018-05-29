class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(!envelopes.size()) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        int dp[envelopes.size()];
        memset(dp, 0, sizeof(dp));
        int res = 1;
        for(int i = 0; i < envelopes.size(); i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
    
    static bool cmp(pair<int, int> p1, pair<int, int> p2) {
        return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
    }
};