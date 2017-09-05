class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 1);
        for(int i = 1; i < rowIndex+1; i++) {
            unsigned long tmp = (unsigned long)res[i-1]*(rowIndex-i+1)/i;
            res[i] = (int)tmp;
        }
        return res;
    }
};