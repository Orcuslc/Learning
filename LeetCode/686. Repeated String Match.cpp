class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int count = 1;
        int i = 0, j = 0;
        while(j < B.size()) {
            if(i > A.size()*B.size()) return -1;
            if(A[i%A.size()] != B[j]) j = 0;
            else j++;
            i++;
        }
        return (i-1)/A.size()+1;
    }
};