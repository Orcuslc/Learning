class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(!matrix.size()) return vector<int>();
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m*n, 0);
        int up = 0, down = m-1, left = 0, right = n-1, count = 0;
        while(1) {
            for(int col = left; col <= right; col++) res[count++] = matrix[up][col];
            if(++up > down) break;
            for(int row = up; row <= down; row++) res[count++] = matrix[row][right];
            if(--right < left) break;
            for(int col = right; col >= left; col--) res[count++] = matrix[down][col];
            if(--down < up) break;
            for(int row = down; row >= up; row--) res[count++] = matrix[row][left];
            if(++left > right) break;
        }
        return res;
    }
};