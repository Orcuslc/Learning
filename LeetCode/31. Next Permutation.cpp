class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size()-1;
        while(index >= 1) {
            if(nums[index-1] < nums[index]) break;
            index--;
        }
        if(index == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int minval = nums[index-1], minindex = nums.size()-1;
        while(minindex >= index) {
            if(nums[minindex] > minval) break;
            minindex--;
        }
        nums[index-1] = nums[minindex]; nums[minindex] = minval;
        sort(nums.begin()+index, nums.end());
    }
};