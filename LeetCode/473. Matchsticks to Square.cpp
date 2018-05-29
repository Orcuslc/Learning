class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int count = 0;
        for(int i: nums) count += i;
        if(count%4 || count == 0) return false;
        
        sort(nums.begin(), nums.end(), cmp);
        vector<int> sides(4, 0);
        
        return dfs(nums, sides, 0, count/4);
    }
    
    static bool cmp(int x, int y) { return x>y; }
    
    bool dfs(vector<int>& nums, vector<int>& sides, int index, int target) {
        if(index == nums.size()) {
            if(sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target) return true;
            else return false;
        }
        for(int i = 0; i < 4; i++) {
            if(sides[i] + nums[index] > target) continue;
            sides[i] += nums[index];
            if(dfs(nums, sides, index+1, target)) return true;
            sides[i] -= nums[index];
        }
        return false;
    }
    

};