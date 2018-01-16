class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numstring(nums.size());
        for(int i = 0; i < nums.size(); i++) numstring[i] = to_string(nums[i]);
        sort(numstring.begin(), numstring.end(), cmp);
        string res = "";
        for(string s: numstring) res += s;
        int index = 0;
        while(res[index] == '0') index++;
        res = res.substr(index == res.size()? res.size()-1:index);
        return res;
    }
    
    static bool cmp(string s, string t) {
        return s+t > t+s;
    }
    
    // static bool cmp(string s, string t) {
    //     if(s.size() >= t.size()) return cmpl(s, t);
    //     else return cmpl(t, s);
    // }
    
    // static bool cmpl(string s, string t) {
    //     for(int i = 0; i < s.size(); i++) {
    //         if(s[i] > t[i%(t.size())]) return true;
    //         else if(s[i] < t[i%t.size()]) return false;
    //     }
    //     return false;
    // }
};