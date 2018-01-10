class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0]+nums[1]+nums[2];
        int first = 0, second = 1, third = nums.size()-1;
        for(first = 0; first < nums.size()-2; first++) {
            if(first && nums[first] == nums[first-1]) continue;
            second = first+1; third = nums.size()-1;
            while(second < third) {
                int sum = nums[first]+nums[second]+nums[third];
                if(abs(sum - target) < abs(closest - target)) closest = sum;
                if(sum == target) return target;
                else if(sum > target) third--;
                else second++;
            }
        }
        return closest;
    }
};