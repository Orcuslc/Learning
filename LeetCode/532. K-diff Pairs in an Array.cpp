class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(!nums.size() || k < 0) return 0;
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;
        int count = 0;
        
        unordered_map<int, int>::iterator it = mp.begin();
        if(k == 0) {
            while(it != mp.end()) {
                if(it->second >= 2) count++;
                it++;
            }
        }
        else {
            while(it != mp.end()) {
                if(mp.find(it->first+k) != mp.end()) count++;
                it++;
            }
        }
        return count;
    }
};