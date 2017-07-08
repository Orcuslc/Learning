class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, click[0], click[1]);
        return board;
    }
    
    bool inBoard(vector<vector<char>> board, int x, int y) {
        return (x>=0 && y>=0 && x<board.size() && y<board[0].size());
    }
    
    void dfs(vector<vector<char>>& board, int x, int y) {
        if(!inBoard(board, x, y)) return;
        if(board[x][y] == 'E') {
            int mine = 0;
            if(inBoard(board, x-1, y) && board[x-1][y] == 'M') mine++;
            if(inBoard(board, x+1, y) && board[x+1][y] == 'M') mine++;
            if(inBoard(board, x, y-1) && board[x][y-1] == 'M') mine++;
            if(inBoard(board, x, y+1) && board[x][y+1] == 'M') mine++;
            if(inBoard(board, x-1, y-1) && board[x-1][y-1] == 'M') mine++;
            if(inBoard(board, x-1, y+1) && board[x-1][y+1] == 'M') mine++;
            if(inBoard(board, x+1, y-1) && board[x+1][y-1] == 'M') mine++;
            if(inBoard(board, x+1, y+1) && board[x+1][y+1] == 'M') mine++;
            if(mine) {
                board[x][y] = mine+'0';
                return;
            }
            else {
                board[x][y] = 'B';
                dfs(board, x-1, y);
                dfs(board, x+1, y);
                dfs(board, x, y-1);
                dfs(board, x, y+1);
                dfs(board, x-1, y-1);
                dfs(board, x-1, y+1);
                dfs(board, x+1, y-1);
                dfs(board, x+1, y+1);
            }       
        }
    }
};

