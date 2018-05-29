class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, F0 = 0;
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
            F0 += i*A[i];
        }
        int Fmax = F0;
        for(int i = A.size()-1; i >= 1; i--) {
            F0 += sum-A.size()*A[i];
            Fmax = max(F0, Fmax);
        }
        return Fmax;
    }
};