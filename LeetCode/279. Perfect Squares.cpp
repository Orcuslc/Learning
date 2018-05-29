class Solution {
public:
    int numSquares(int n) {
        int sqroot = sqrt(n);
        if(sqroot*sqroot == n) return 1;
        
        while(n % 4 == 0) n /= 4;
        if(n % 8 == 7) return 4;
        
        for(int i = 1; i <= sqroot; i++) {
            int remain = n - i*i;
            int sqremain = sqrt(remain);
            if(sqremain*sqremain == remain) return 2;
        }
        return 3;
    }
    
};

class Solution {
public:
    int numSquares(int n) {
        if(n <= 0) return 0;
        static vector<int> num({0});
        while(num.size() <= n) {
            int m = num.size(), minSquare = INT_MAX;
            for(int i = 1; i*i <= m; i++) minSquare = min(minSquare, num[m - i*i]+1);
            num.push_back(minSquare);
        }
        return num[n];
    }
};