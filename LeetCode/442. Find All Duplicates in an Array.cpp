class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(!nums.size()) return nums;
        sort(nums.begin(), nums.end());
        int now = nums[0];
        vector<int> res;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == now) res.push_back(now);
            else now = nums[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(!nums.size()) return nums;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i])-1;
            if(nums[index] < 0) res.push_back(index+1);
            nums[index] = -nums[index];
        }
        return res;
    }
};