class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(!nums.size()) return vector<int>();
        vector<int> res(nums.size(), 0);
        res.back() = -1;
        for(int i = nums.size()-2; i >= 0; i--) {
            int index = i+1;
            while(nums[i] >= nums[index] && res[index] != -1) {
                index = res[index];
            }
            if(nums[index] > nums[i]) res[i] = index;
            else res[i] = -1;
        }
        for(int i = nums.size()-1; i >= 0; i--) {
            if(res[i] != -1) continue;
            int index = (i+1)%nums.size();
            while(nums[i] >= nums[index] && res[index] != -1) {
                index = res[index];
            }
            if(nums[index] > nums[i]) res[i] = index;
            else res[i] = -1;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(res[i] != -1) res[i] = nums[res[i]];
        }
        return res;
    }
    
};