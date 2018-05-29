class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n <= 1) return true;
        int bit = n&1;
        while(n) {
            n >>= 1;
            int newbit = n&1;
            if(newbit == bit) return false;
            bit = newbit;
        }
        return true;
    }
};