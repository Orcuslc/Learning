class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, maxsum;
        for(int i = 0; i < k; i++) sum += nums[i];
        maxsum = sum;
        for(int i = k; i < nums.size(); i++) {
            sum += nums[i]-nums[i-k];
            if(sum > maxsum) maxsum = sum; 
        }
        return maxsum/k;
    }
};