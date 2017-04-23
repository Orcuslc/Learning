class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int dp = 0, sum = 0, n = A.size();
        for(int i = 2; i < n; i++) {
            dp = ((A[i] - A[i-1]) == (A[i-1] - A[i-2])) ? (dp+1):(0);
            sum += dp;
        }
        return sum;
    }
};