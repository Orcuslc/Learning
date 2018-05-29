class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9) return n;
        else if(n <= 189) return find(n-9, 2);    
        else if(n <= 2889) return find(n-189, 3);
        else if(n <= 38889) return find(n-2889, 4);
        else if(n <= 488889) return find(n-38889, 5);
        else if(n <= 5888889) return find(n-488889, 6);
        else if(n <= 68888889) return find(n-5888889, 7);
        else if(n <= 788888889) return find(n-68888889, 8);
        else return find(n-788888889, 9);
    }
    
    int find(int n, int d) { // d: digit
        int num = (n-1)/d+(int)pow(10, d-1);
        int rem = d-(n-1)%d-1;
        while(rem--) {
            num /= 10;
        }
        return num%10;
    }
};