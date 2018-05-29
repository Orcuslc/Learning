class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        reverse(S.begin(), S.end());
        string res = ""; 
        int count = 0;
        for(int i = 0; i < S.size(); i++) {
            if(count == K) {
                res += '-'; count = 0;
            }
            if(S[i] >= 'a' && S[i] <= 'z') {
                count++; res += S[i] - 32;
            }
            else if((S[i] >= 'A' && S[i] <= 'Z') || S[i] >= '0' && S[i] <= '9') {
                count++; res += S[i];
            }
        }
        reverse(res.begin(), res.end());
        return res[0] == '-'? res.substr(1, res.size()-1):res;
    }
};