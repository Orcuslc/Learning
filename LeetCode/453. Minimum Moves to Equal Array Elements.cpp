class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0, min = INT_MAX;
        for(int i: nums) if(i < min) min = i;
        for(int i: nums) res += (i-min);
        return res;
    }
};

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0, min = INT_MAX;
        for(int i: nums) {
            if(i < min) min = i;
            res += i;
        }
        return res - nums.size()*min;
    }
};