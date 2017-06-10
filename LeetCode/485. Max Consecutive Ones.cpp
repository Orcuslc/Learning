class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int dp = 0, local = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                local++;
                dp = dp>local?dp:local;
            }
            else local = 0;
        }
        return dp;
    }
};