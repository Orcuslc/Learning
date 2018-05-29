class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = INT_MAX, sum = 0, start = 0, end = 0;
        while(end < nums.size()) {
            sum += nums[end++];
            while(sum >= s) {
                sum -= nums[start++];
                minLen = min(minLen, end-start+1);
            }
        }
        return minLen == INT_MAX?0:minLen;
    }
};