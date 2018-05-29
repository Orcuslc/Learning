class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        int dict[n] = {0};
        for(int num: nums) {
            dict[num]++;
        }
        int take = 0, skip = 0;
        for(int i = 1; i < n; i++) {
            int take_i = skip + dict[i]*i;
            skip = max(take, skip);
            take = take_i;
        }
        return max(skip, take);
    }
};