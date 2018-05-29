class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) { 
            for(int j = 0; j < board[0].size(); j++) {
                    bool res = false;
                    // vector<vector<int> > vis(board.size(), vector<int>(board[0].size(), 0));
                    // dfs(board, vis, i, j, 1, word, res);
                    dfs(board, i, j, 0, word, res);
                    if(res) return true;
            }
        }
        return false;
    }
    
    void dfs(vector<vector<char> >& board, int i, int j, int k, string& word, bool& res) {
        // cout << k << endl;
        if(k == word.size()) {
            res = true;
            return;
        }
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size()) return;
        if(board[i][j] != word[k]) return;
        // char s = board[i][j];
        // board[i][j] = '#';
        board[i][j] ^= 256;
        // if(j > 0 && board[i][j-1] == word[k]) dfs(board, i, j-1, k+1, word, res);
        // if(j < board[0].size()-1 && board[i][j+1] == word[k]) dfs(board, i, j+1, k+1, word, res);
        // if(i > 0 && board[i-1][j] == word[k]) dfs(board, i-1, j, k+1, word, res);
        // if(i < board.size()-1 && board[i+1][j] == word[k]) dfs(board, i+1, j, k+1, word, res);
        dfs(board, i, j-1, k+1, word, res);
        dfs(board, i, j+1, k+1, word, res);
        dfs(board, i-1, j, k+1, word, res);
        dfs(board, i+1, j, k+1, word, res);
        // board[i][j] = s;
        board[i][j] ^= 256;
        return;
    }
    
    // void dfs(vector<vector<char> >& board, vector<vector<int> >& vis, int i, int j, int k, string& word, bool& res) {
    //     if(k == word.size()) {
    //         res = true;
    //         return;
    //     }
    //     vis[i][j] = 1;
    //     if(j > 0 && !vis[i][j-1] && board[i][j-1] == word[k]) dfs(board, vis, i, j-1, k+1, word, res);
    //     if(j < board[0].size()-1 && !vis[i][j+1] && board[i][j+1] == word[k]) dfs(board, vis, i, j+1, k+1, word, res);
    //     if(i > 0 && !vis[i-1][j] && board[i-1][j] == word[k]) dfs(board, vis, i-1, j, k+1, word, res);
    //     if(i < board.size()-1 && !vis[i+1][j] && board[i+1][j] == word[k]) dfs(board, vis, i+1, j, k+1, word, res);
    //     return;
    // }
};


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) { 
            for(int j = 0; j < board[0].size(); j++) {
                if(dfs(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char> >& board, int i, int j, int k, string& word) {
        if(k == word.size()) return true;
        if(i < 0 || j < 0 || i == board.size() || j == board[0].size()) return false;
        if(board[i][j] != word[k]) return false;
        char s = board[i][j];
        board[i][j] = '#';
        bool res =  dfs(board, i, j-1, k+1, word) || dfs(board, i, j+1, k+1, word) || dfs(board, i-1, j, k+1, word) || dfs(board, i+1, j, k+1, word);
        board[i][j] = s;
        return res;
    }
};