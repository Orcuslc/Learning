class Solution {
public:
    int superPow(int a, vector<int>& b) {
        // using Euler's-theorem, phi(1337) = phi(7*191) = 1140;
        // so a^{1140} == 1(mod 1337);
        // Let b = 1140*p+q, then a^b == a^q(mod 1337); 
        int q = 0;
        for(int i = 0; i < b.size(); i++) q = (q*10+b[i])%1140;
        a = a%1337;
        return quickpow(a, q);
    }
    
    int quickpow(int a, int q) {
        if(q == 0) return 1;
        if(q&1) {
            int half = quickpow(a, (q-1)/2)%1337;
            return (a*half*half)%1337;
        }
        else {
            int half = quickpow(a, q/2)%1337;
            return (half*half)%1337;
        }
    }
};