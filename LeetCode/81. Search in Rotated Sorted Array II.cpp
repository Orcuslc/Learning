class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(!nums.size()) return false;
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int mid = (left+right)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > nums[right]) { // rotated vals are in the right part
                if(nums[mid] > target && nums[right] < target) { // target are in the left part
                    right = mid;
                }
                else { // nums[mid] < target: target in the right part; nums[right] > target: the same;
                    left = mid+1;
                }
            }
            else if(nums[mid] < nums[right]) {
                if(nums[mid] < target && nums[right] >= target) {
                    left = mid+1;
                }
                else right = mid;
            }
            else { // nums[mid] == nums[right]
                right--;
            }
        }
        return nums[left] == target? true:false;
    }
};