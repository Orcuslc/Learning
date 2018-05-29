class NumArray {
    vector<int> presum;
public:
    NumArray(vector<int> nums) {
        presum.resize(nums.size()+1);
        presum[0] = 0;
        for(int i = 1; i <= nums.size(); i++) {
            presum[i] = presum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return presum[j+1]-presum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */