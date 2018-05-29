class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int count = 1;
        for(int j = 2; j <= sqrt(num); j++) {
            if(num % j == 0) count += j + num/j;
        }
        return count == num;
    }
    
};