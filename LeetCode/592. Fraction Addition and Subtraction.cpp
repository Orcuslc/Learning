class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0, den = 1, x, y;
        stringstream ss(expression);
        char _;
        while(ss >> x >> _ >> y) {
            num = num*y + den*x;
            den *= y;
            int g = gcd(num, den);
            num /= g;
            den /= g;
        }
        string res = "";
        if(num < 0 ^ den < 0) res += "-";
        return res + to_string(abs(num)) + "/" + to_string(abs(den));
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