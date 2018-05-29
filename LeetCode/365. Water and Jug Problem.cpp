class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        // can be regraded as Euclidean method to get gcd(x, y);
        // check if gcd(x, y) | z --> Bezout theorem;
        if(x+y < z) return false;
        if(x == z || y == z || x+y == z) return true;
        return z%gcd(x, y) == 0;
    }
    
    int gcd(int x, int y) {
        while(y != 0) {
            int tmp = y;
            y = x%y;
            x = tmp;
        }
        return x;
    }
};