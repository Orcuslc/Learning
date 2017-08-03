class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() >= b.size()) return add(a, b);
        else return add(b, a);
    }
    
    string add(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for(int i = 0; i < b.size(); i++) {
            int sum = a[i]-'0' + b[i]-'0' + carry;
            a[i] = sum%2+'0';
            carry = sum/2;
        }
        for(int i = b.size(); i < a.size(); i++) {
            int sum = a[i]-'0' + carry;
            a[i] = sum%2+'0';
            carry = sum/2;
        }
        if(carry) a += '1';
        reverse(a.begin(), a.end());
        return a;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0; string res(max(a.size(), b.size()), '0');
        for(int i = 0; i < max(a.size(), b.size()); i++) {
            int sum = (i < a.size()? a[i]-'0': 0) + (i < b.size()? b[i]-'0': 0) + carry;
            res[i] = sum%2 + '0';
            carry = sum/2;
        }
        if(carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};