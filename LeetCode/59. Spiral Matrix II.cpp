class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));
        int count = 1, i = 0;
        while(count <= n*n) {
            int j = i;
            while(j < n-i) res[i][j++] = count++;
            j = i+1;
            while(j < n-i) res[j++][n-i-1] = count++;
            j = n-i-2;
            while(j > i) res[n-i-1][j--] = count++;
            j = n-i-1;
            while(j>i) res[j--][i] = count++;
            i++;
        }
        return res;
    }
};