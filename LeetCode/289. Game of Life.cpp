class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0;
                for(int row = max(0, i-1); row <= min(i+1, m-1); row++) {
                    for(int col = max(0, j-1); col <= min(j+1, n-1); col++) {
                        count += board[row][col]&1; // use a two-bit value to represent the status, with the last bit representing the original status of board[i][j];
                        // 00: die->die;
                        // 01: live->die;
                        // 10: die->live;
                        // 11: live->live;
                    }
                }
                count -= board[i][j]&1;
                if(board[i][j] == 0) { // now dead;
                    if(count == 3) board[i][j] = 2; // live
                }
                else { // now alive
                    if(count < 2) board[i][j] = 1; // die
                    else if(count <= 3) board[i][j] = 3; // live;
                    else board[i][j] = 1; // die;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};