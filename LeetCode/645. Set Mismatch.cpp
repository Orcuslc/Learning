class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp; int sum = 0, dup;
        for(int i : nums) {
            mp[i]++;
            if(mp[i] == 2) dup = i;
            sum += i;
        }
        int mis = nums.size()*(nums.size()+1)/2+dup-sum;
        vector<int> res;
        res.push_back(dup); res.push_back(mis);
        return res;
    }
};