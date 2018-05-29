class Solution {
public:
    long getIndex(long i, long t) {
        if(i < 0) return (i+1)/(t+1)-1;
        else return i/(t+1);
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0) return false;
        unordered_map<long, long> mp;
        
        for(int i = 0; i < nums.size(); i++) {
            long index = getIndex((long)nums[i], (long)t);
            if(mp.find(index) != mp.end()) return true;
            if(mp.find(index-1) != mp.end() && abs(nums[i]-mp[index-1]) <= t) return true;
            if(mp.find(index+1) != mp.end() && abs(nums[i]-mp[index+1]) <= t) return true;
            mp[index] = nums[i];
            if(i >= k) mp.erase(getIndex(nums[i-k], t));
        }
        return false;
    }
};