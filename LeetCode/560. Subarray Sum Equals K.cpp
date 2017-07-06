class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for(int i : nums) {
            sum += i;
            count += mp[sum-k];
            mp[sum]++;
        }
    	return count;
    }
};