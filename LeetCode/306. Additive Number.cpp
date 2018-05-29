class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i <= num.size()/2; i++) {
            for(int j = 1; j <= (num.size()-i)/2; j++) {
                if(isAdditive(num.substr(0, i), num.substr(i, j), num.substr(i+j))) return true;
            }
        }
        return false;
    }
    
    bool isAdditive(string a, string b, string c) {
        if((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0')) return false;
        string s = add(a, b);
        if(s == c) return true;
        else if(c.size() <= s.size()) return false;
        else if(c.substr(0, s.size()) != s) return false;
        return isAdditive(b, s, c.substr(s.size()));
    }
    
    string add(string a, string b) {
        string res;
        int i = a.size()-1, j = b.size()-1, carry = 0;
        while(i >= 0 || j >= 0) {
            int sum = (i >= 0? a[i--]-'0': 0) + (j >= 0? b[j--]-'0': 0) + carry;
            res += (sum%10 + '0');
            carry = sum/10;
        }
        if(carry) res += carry + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};