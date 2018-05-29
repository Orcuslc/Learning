class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int row = M.size(), col = M[0].size();
        if(!row) return vector<vector<int>>();
        vector<vector<int>> res(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int num = 0, sum = 0; 
                for(int k : {-1, 0, 1}) {
                    for(int l: {-1, 0, 1}) {
                        if(i + k >= 0 && i + k < row && j + l >= 0 && j + l < col) {
                            num++;
                            sum += M[i+k][j+l];
                        }
                    }
                }
                res[i][j] = sum/num;
            }
        }
        return res;
    }
};