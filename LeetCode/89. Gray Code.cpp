class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return vector<int>(1, 0);
        vector<int> res = {0, 1};
        for(int i = 1; i < n; i++) {
            int m = 1 << i;
            vector<int> tmp(res.rbegin(), res.rend());
            for(int& s: tmp) s += m;
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        return res;
    }
};