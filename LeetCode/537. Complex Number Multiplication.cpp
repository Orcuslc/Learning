class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int aReal = 0, bReal = 0, aImag = 0, bImag = 0;
        int index = 0; while(a[index++] != '+') ;
        getDigit(a, 0, index-1, aReal); getDigit(a, index, a.size(), aImag);
        index = 0; while(b[index++] != '+') ;
        getDigit(b, 0, index-1, bReal); getDigit(b, index, b.size(), bImag);
        int real = aReal*bReal - aImag*bImag, imag = aReal*bImag + aImag*bReal;
        return to_string(real)+'+'+to_string(imag)+'i';
    }
        
    void getDigit(string& a, int left, int right, int& num) {
        int sgn = 1, index = left;
        if(a[index] == '-') {
            sgn = -1;
            index++;
        }
        for(int i = index; i < right; i++) {
            if(a[i] != 'i') num = num*10 + a[i] - '0';
        }
        num *= sgn;
    }
};