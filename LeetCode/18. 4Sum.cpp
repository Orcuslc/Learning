class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res; if(nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3; i++) {
            for(int j = i+1; j < nums.size()-2; j++) {
                int front = j+1, back = nums.size()-1, ntarget = target-(nums[i]+nums[j]);
                while(front < back) {
                    int sum = nums[front]+nums[back];
                    if(sum < ntarget) front++;
                    else if(sum > ntarget) back--;
                    else {
                        vector<int> now = {nums[i], nums[j], nums[front], nums[back]};
                        res.push_back(now);
                        while(front < back && nums[front] == now[2]) front++;
                        while(back > front && nums[back] == now[3]) back--;
                    }
                    while(j < nums.size()-3 && nums[j+1] == nums[j]) j++;
                }
                while(i < nums.size()-4 && nums[i+1] == nums[i]) i++;
            }
        }
        return res;
    }
};