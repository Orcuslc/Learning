class Solution {
    const int mod = 1000000007;
public:
    int checkRecord(int n) {
        if(n == 0) return 0;
        long one_A_two_L[2] = {0, 0}, one_A_one_L[2] = {0, 0}, one_A_no_L[2] = {0, 1};
        long no_A_two_L[2] = {0, 0}, no_A_one_L[2] = {0, 1}, no_A_no_L[2] = {0, 1};
        for(int i = 2; i <= n; i++) {
            one_A_two_L[0] = one_A_one_L[1] % mod; // only add L on the back;
            one_A_one_L[0] = one_A_no_L[1] % mod; // same;
            one_A_no_L[0] = (one_A_two_L[1] + one_A_one_L[1] + one_A_no_L[1] + no_A_two_L[1] + no_A_one_L[1] + no_A_no_L[1]) % mod; // add P, P, P, A, A, A;
            no_A_two_L[0] = no_A_one_L[1] % mod; // add L;
            no_A_one_L[0] = no_A_no_L[1] % mod; // same;
            no_A_no_L[0] = (no_A_no_L[1] + no_A_one_L[1] + no_A_two_L[1]) % mod; // only add P;
            one_A_two_L[1] = one_A_two_L[0];
            one_A_one_L[1] = one_A_one_L[0];
            one_A_no_L[1] = one_A_no_L[0];
            no_A_two_L[1] = no_A_two_L[0];
            no_A_one_L[1] = no_A_one_L[0];
            no_A_no_L[1] = no_A_no_L[0];
        }
        return (one_A_two_L[1] + one_A_one_L[1] + one_A_no_L[1] + no_A_two_L[1] + no_A_one_L[1] + no_A_no_L[1]) % mod;
    }
};