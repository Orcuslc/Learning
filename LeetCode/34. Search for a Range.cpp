class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, pos = -1;
        while(left <= right) {
            int mid = (left+right)/2;
            if(nums[mid] == target) {
                pos = mid; break;
            }
            else if(nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        vector<int> res;
        if(pos == -1) {
            res.push_back(-1); res.push_back(-1); return res;
        }
        left = right = pos;
        while(--left >= 0) {
            if(nums[left] == nums[pos]) ;
            else break;
        }
        while(++right < nums.size()) {
            if(nums[right] == nums[pos]) ;
            else break;
        }
        res.push_back(left+1); res.push_back(right-1);
        return res;
    }
};