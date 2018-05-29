class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size() == 1) return nums[0];
        return max(dp(nums, 0, nums.size()-2), dp(nums, 1, nums.size()-1));
    }
    
    int dp(vector<int>& nums, int start, int end) {
        int first = 0, second = 0;
        for(int i = start; i <= end; i++) {
            int tmp = max(first + nums[i], second);
            first = second;
            second = tmp;
        }
        return second;
    }
};