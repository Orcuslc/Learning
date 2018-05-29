class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> numset(nums.begin(), nums.end());
        if(numset.size() < 3) return *numset.rbegin();
        set<int>::reverse_iterator it = numset.rbegin(); it++; it++;
        return *it;
    }
};