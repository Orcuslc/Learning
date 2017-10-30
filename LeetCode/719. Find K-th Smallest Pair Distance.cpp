class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int right = nums.back() - nums[0];
        int left = INT_MAX;
        for(int i = 1; i < nums.size(); i++) {
            left = min(left, nums[i]-nums[i-1]);
        }
        while(left < right) {
            int mid = left + (right-left)/2;
            // number of pairs with the number of (difference less than mid) < k --> search the right part;
            if(count(nums, mid) < k) {
                left = mid+1;
            }
            else right = mid;
        }
        return left;
    }
    
    int count(vector<int>& nums, int val) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int end = upper_bound(nums.begin()+i, nums.end(), nums[i]+val)-nums.begin();
            res += (end - i - 1);
        }
        return res;
    }
};