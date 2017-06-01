class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int res = mp[s.back()];
        int val[s.length()];
        for(int i = 0; i < s.length(); i++) {
            val[i] = mp[s[i]];
        }
        for(int i = s.length()-2; i >= 0; i--) {
            if(val[i] < val[i+1]) {
                res -= val[i];
            }
            else res += val[i];
        }
        return res;
    }
};