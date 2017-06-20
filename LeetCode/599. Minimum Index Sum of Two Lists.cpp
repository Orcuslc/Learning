class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> mp;
        int size = list1.size()+list2.size();
        for(int i = 0; i < list1.size(); i++) mp[list1[i]] += i - size;
        for(int i = 0; i < list2.size(); i++) mp[list2[i]] += i - size;
        int val = INT_MAX;
        vector<string> res;
        for(auto i : mp) {
            if(i.second == val) res.push_back(i.first);
            else if(i.second < val) {
                val = i.second;
                res.clear();
                res.push_back(i.first);
            } 
        }
        return res;
    }
};