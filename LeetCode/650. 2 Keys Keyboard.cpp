class Solution {
    
public:
    int minSteps(int n) {
        int s[n+1] = {1};
        for(int i = 2; i <= n; i++) {
            s[i] = i;
            for(int j = i/2; j > 1; j--) {
                if(i%j == 0) s[i] = min(s[j]+i/j, s[i]);
            }
        }
        return s[n];
    }
};