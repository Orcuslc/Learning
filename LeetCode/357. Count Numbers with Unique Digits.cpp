class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // the amount of n-digit number with unique digits is C_9^1*C_9^1*...*C_(11-n)^1;
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(n == 1) return 10;
        else if(n == 2) return 91;
        else if(n == 3) return 739;
        else if(n == 4) return 5275;
        else if(n == 5) return 32491;
        else if(n == 6) return 168571;
        else if(n == 7) return 712891;
        else if(n == 8) return 2345851;
        else if(n == 9) return 5611771;
        else return 8877691;
    }
    
    
};