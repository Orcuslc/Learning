class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        long count = 0;
        dfs(m, n, N, 0, count, i, j);
        return count%(1000000007);
    }
    
    void dfs(int m, int n, int N, int num, long& count, int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0) {
            count++;
            return;
        }
        for(int k = 0; k < 4; k++) {
            if(num < N) dfs(m, n, N, num+1, count, i+dir[k][0], j+dir[k][1]);
        }
    }
    
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        long dp[51][51][51] = {0};
        for(int Ni = 1; Ni <= N; Ni++) {
            for(int mi = 0; mi < m; mi++) {
                for(int ni = 0; ni < n; ni++) {
                    dp[mi][ni][Ni] = ((mi == 0? 1:dp[mi-1][ni][Ni-1])
                                + (mi == (m-1)? 1:dp[mi+1][ni][Ni-1])
                                + (ni == 0? 1:dp[mi][ni-1][Ni-1])
                                + (ni == (n-1)? 1:dp[mi][ni+1][Ni-1]))%1000000007;
                }
            }
        }
        return dp[i][j][N];
    }
};