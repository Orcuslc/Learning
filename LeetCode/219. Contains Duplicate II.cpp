class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(!nums.size()) return false;
        unordered_map<int, vector<int> > mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]].push_back(i);
        unordered_map<int, vector<int> >::iterator it = mp.begin();
        while(it != mp.end()) {
            if(it->second.size() >= 2) {
                for(int i = 0; i < it->second.size()-1; i++) {
                    for(int j = i+1; j < it->second.size(); j++) if(abs(it->second[i] - it->second[j]) <= k) return true;
                }
            }
            it++;
        }
        return false;
    }
};