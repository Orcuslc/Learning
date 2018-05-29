class Solution {
public:
    int longestPalindrome(string s) {
        int count[127] = {0};
        for(char i : s) {
            count[i]++;
        }
        int res = 0, odd = 0, oddcount = 0;
        for(int i = 65; i <= 122; i++) {
            if(count[i] % 2 == 0) res += count[i];
            else {
                odd += count[i];
                oddcount++;
            }
        }
        res += oddcount > 0? odd - oddcount + 1:0;
        return res;
    }
};