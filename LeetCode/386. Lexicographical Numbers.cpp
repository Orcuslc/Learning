class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int now = 1;
        for(int i = 0; i < n; i++) {
            res[i] = now;
            if(now*10 <= n) now *= 10;
            else {
                if(now >= n) now /= 10;
                now += 1;
                while(now % 10 == 0) now /= 10;
            }
        }
        return res;
    }
};