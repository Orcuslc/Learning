class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        for(int j = 0; j < board[0].size(); j++) {
            if(board[0][j] == 'O') pre(board, 0, j);
            if(board[board.size()-1][j] == 'O') pre(board, board.size()-1, j);
        }
        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == 'O') pre(board, i, 0);
            if(board[i][board[0].size()-1] == 'O') pre(board, i, board[0].size()-1);
        }
        for(int i = 1; i < board.size()-1; i++) {
            for(int j = 1; j < board[0].size()-1; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
    
    void pre(vector<vector<char> >& board, int i, int j) {
        // if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        if(board[i][j] == 'O') {
            board[i][j] = 'A';
            if(i > 1) pre(board, i-1, j);
            if(i < board.size()-1) pre(board, i+1, j);
            if(j > 1) pre(board, i, j-1);
            if(j < board[0].size()-1) pre(board, i, j+1);
        }
        else return;
    }
};