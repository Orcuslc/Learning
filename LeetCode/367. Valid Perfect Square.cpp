class Solution {
public:
    bool isPerfectSquare(int num) {
        int sqroot = sqrt(num);
        if(sqroot*sqroot == num) return true;
        else return false;
    }
};