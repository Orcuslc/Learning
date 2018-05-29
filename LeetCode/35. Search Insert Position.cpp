class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos;
        if(nums[0] > target) return 0;
        if(nums[nums.size()-1] < target) return nums.size();
        bisearch(nums, 0, nums.size(), target, pos);
        return pos;
    }
    
    void bisearch(vector<int>& nums, int left, int right, int target, int& pos) {
        if(left == right-1) {
            if(nums[left] == target) {
                pos = left; return;
            }
            else if(nums[right] == target) {
                pos = right; return;
            }
            else if(nums[left] < target && nums[right] > target) {
                pos = right; return;
            }
            else return;
        } 
        int mid = (left+right)/2;
        bisearch(nums, left, mid, target, pos);
        bisearch(nums, mid, right, target, pos);
    }

};