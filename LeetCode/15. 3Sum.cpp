class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i], front = i+1, back = nums.size()-1;
            while(front < back) {
                int sum = nums[front] + nums[back];
                if(sum < target) front++;
                else if(sum > target) back--;
                else {
                    vector<int> now = {nums[i], nums[front], nums[back]};
                    res.push_back(now);
                    while(front < back && nums[front] == now[1]) front++;
                    while(back > front && nums[back] == now[2]) back--;
                }
                while(i < nums.size()-1 && nums[i+1] == nums[i]) i++;
            }
        }
        return res;
    }
};