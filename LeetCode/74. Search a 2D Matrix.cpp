class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return false;
        int row = INT_MAX, col = INT_MAX;
        rowbisearch(matrix, target, row, 0, matrix.size()-1);
        cout << row << endl;
        if(row == INT_MAX) return false;
        colbisearch(matrix, target, row, col, 0, matrix[0].size()-1);
        return col == INT_MAX? false:true;
    }
    
    void rowbisearch(vector<vector<int> >& matrix, int target, int& row, int left, int right) { // return x if the first element of x_th row is larger than target
        if(left <= right) {
            int mid = (left+right)/2;
            if(mid == 0) {
                if(target < matrix[0][0]) return;
                else if(matrix.size() <= 1 || target < matrix[1][0]) {
                    row = 0;
                    return;
                }
                else {
                    row = 1;
                    return;
                }
            }
            if(mid == matrix.size()-1) {
                row = matrix.size()-1;
                return;
            }
            if(matrix[mid][0] > target && matrix[mid-1][0] <= target) {
                row = mid-1;
                return;
            }
            if(matrix[mid][0] <= target && matrix[mid+1][0] > target) {
                row = mid;
                return;
            }
            else if(matrix[mid][0] > target) {
                rowbisearch(matrix, target, row, left, mid-1);
            }
            else rowbisearch(matrix, target, row, mid+1, right);
        }
    }
    
    void colbisearch(vector<vector<int> >& matrix, int target, int row, int& col, int left, int right) {
        if(left <= right) {
            int mid = (left+right)/2;
            if(matrix[row][mid] == target) {
                col = mid;
                return;
            }
            else if(matrix[row][mid] > target) {
                colbisearch(matrix, target, row, col, left, mid-1);
            }
            else
                colbisearch(matrix, target, row, col, mid+1, right);
        }
    }
};