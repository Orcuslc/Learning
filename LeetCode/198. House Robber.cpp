class Solution {
public:
    int rob(vector<int>& nums) {
        int excluded = 0, included = 0;
        for(int i : nums) {
            int tmp = included;
            included = excluded + i;
            excluded = max(tmp, excluded);
        }
        return max(included, excluded);
    }
};