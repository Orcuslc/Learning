class Solution {
public:
    string longestPalindrome(string s) {
        int dp = 1, start = 0;
        for(int i = 0; i < s.size();) {
            if(s.size()-i <= dp/2) break;
            int j = i, k = i;
            while(k < s.size()-1 && s[k+1] == s[k]) k++;
            i = k+1;
            while(k < s.size()-1 && j > 0) {
                if(s[k+1] == s[j-1]) {
                    k++; j--;
                }
                else break;
            }
            if(k-j+1 > dp) {
                dp = k-j+1;
                start = j;
            }
        }
        return s.substr(start, dp);
    }
};