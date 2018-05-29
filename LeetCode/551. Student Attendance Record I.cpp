class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0, late = 0;
        for(char i: s) {
            if(i == 'A') {
                absent++;
                late = 0;
            }
            else if(i == 'L') late++;
            else late = 0;
            if(absent > 1 || late > 2) return false;
        }
        return true;
    }
};