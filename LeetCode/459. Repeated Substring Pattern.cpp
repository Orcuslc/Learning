class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> factors;
        for(int i = 1; i <= n/2; i++) if(n%i == 0) factors.push_back(i);
        for(int factor: factors) {
            bool flag = true;
            string sub = s.substr(0, factor);
            for(int i = 1; i < n/factor; i++) if(s.substr(i*factor, factor) != sub) {
                flag = false;
                break;
            }
            if(flag) return true;
        }
        return false;
    }
};