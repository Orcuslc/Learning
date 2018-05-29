class Solution {
public:
    string convertToBase7(int num) {
        if(!num) return "0";
        string res; bool neg = false;
        if(num < 0) {
            neg = true;
            num = -num;
        }
        while(num) {
            int remainder = num%7;
            num /= 7;
            res += to_string(remainder);
        }
        if(neg) res += '-';
        reverse(res.begin(), res.end());
        return res;
    }
};