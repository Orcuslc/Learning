class Solution {
public:
    string minWindow(string s, string t) {
        int chart[128], exist[128];
        memset(chart, 0, sizeof(chart)); memset(exist, 0, sizeof(exist));
        for(char c: t) {
            chart[c]++;
            exist[c] = 1;
        }
        int left = 0, right = -1;
        int minLen = INT_MAX, minleft = 0, count = t.size();
        while(left < (int)s.size() && right < (int)s.size()) {
            if(count) {
                right++;
                chart[s[right]]--;
                if(exist[s[right]] && chart[s[right]] >= 0) count--;
            }
            else {
                if(minLen > right-left+1) {
                    minLen = right-left+1;
                    minleft = left;
                }
                chart[s[left]]++;
                if(exist[s[left]] && chart[s[left]] > 0) count++;
                left++;
            }
        }
        if(minLen == INT_MAX) return "";
        return s.substr(minleft, minLen);
    }
};