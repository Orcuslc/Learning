class Solution {
public:
    int climbStairs(int n) {
        double x = sqrt(5);
        double res = 1/x * (pow((1+x)/2, n+1) - pow((1-x)/2, n+1));
        return (int)res;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        int v1 = 1, v2 = 1;
        for(int i = 1; i < n; i++) {
            int tmp = v2;
            v2 = v1 + v2;
            v1 = tmp;
        }
        return v2;
    }
};