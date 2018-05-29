class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(!nums.size()) return -1;
        vector<int> sums(nums.size(), 0);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sums[i] = sum;
        }
        if(sum - sums[0] == 0) return 0;
        for(int i = 1; i < nums.size(); i++) {
            if(sums[i-1] == sum-sums[i]) return i;
        }
        return -1;
    }
};