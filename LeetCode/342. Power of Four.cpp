class Solution {
public:
    bool isPowerOfFour(int num) {
        return 1 << (int)log2(num) == num && (int)log2(num) % 2 == 0;
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num & (num-1)) == 0 && (num & 0x55555555) != 0;
    }
};