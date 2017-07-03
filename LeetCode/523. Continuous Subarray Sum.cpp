class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, pre = 0, local = 0;
        unordered_set<int> s;
        for(int i : nums) {
            sum += i;
            local = (k == 0 ? sum:sum%k);
            if(s.count(local)) return true;
            s.insert(pre);
            pre = local;
        }
        return false;
    }
};