class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(!nums.size()) return 0;
        map<int, int> freq;
        int len = 0, last = 0, lastfreq = 0;
        for(int i: nums) freq[i]++;
        
        map<int, int>::iterator it = freq.begin();
        for(; it != freq.end(); it++) {
            if(lastfreq && it->first == last+1) len = max(len, it->second+lastfreq);
            last = it->first;
            lastfreq = it->second;
        }
        return len;
    }
};