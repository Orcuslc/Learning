class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int MAX = 10001;
        int row = matrix.size();
        int col = matrix[0].size();
        
        queue<pair<int, int>> q;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) q.push(make_pair(i, j));
                else matrix[i][j] = MAX;
            }
        }
        vector<pair<int, int>> direction;
        direction.push_back(make_pair(-1, 0)); direction.push_back(make_pair(1, 0));
        direction.push_back(make_pair(0, -1)); direction.push_back(make_pair(0, 1));
        while(!q.empty()) {
            pair<int, int> point = q.front();
            q.pop();
            for(int i = 0; i < direction.size(); i++) {
                int nrow = point.first + direction[i].first;
                int ncol = point.second + direction[i].second;
                if(nrow < 0 || nrow >= row || ncol < 0 || ncol >= col) continue;
                if(matrix[nrow][ncol] <= matrix[point.first][point.second]+1) continue;
                q.push(make_pair(nrow, ncol));
                matrix[nrow][ncol] = matrix[point.first][point.second]+1;
            }
        }
        return matrix;
    }
};