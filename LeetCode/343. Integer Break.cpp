class Solution {
public:
    int integerBreak(int n) {
        int x = floor(n/exp(1)), y = x+1, z = x-1;
        if(x < 2) return _break(n, 2);
        return max(max(_break(n, x), _break(n, y)), _break(n, z));
    }
    
    int _break(int n, int x) {
        int val = n/x, remainder = n%x;
        return pow(val+1, remainder)*pow(val, x-remainder);
    }
};