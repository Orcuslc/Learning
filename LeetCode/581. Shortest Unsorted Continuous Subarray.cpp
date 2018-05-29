class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right && nums[left] <= nums[left+1]) left++;
        while(right > left && nums[right] >= nums[right-1]) right--;
        int res = 0;
        if(right > left) {
            int min = INT_MAX, max = INT_MIN;
            for(int i = left; i <= right; i++) {
                if(nums[i] > max) max = nums[i];
                if(nums[i] < min) min = nums[i];
            }
            while(left >= 0 && nums[left] > min) left--;
            while(right < nums.size() && nums[right] < max) right++;
            res = right - left - 1;
        }
        return res;
    }
};