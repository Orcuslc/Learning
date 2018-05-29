class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = (nums[0] < k);
        for(int i = 1; i < nums.size(); i++) {
            int local = nums[i];
            res += (local < k);
            for(int j = i-1; j >= 0; j--) {
                local *= nums[j];
                if(local >= k) break;
                else res++;
            }
        }
        return res;
    }
};