class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int alpha[26] = {0};
        for(char c: target) alpha[c-'a']++;
        vector<vector<int>> nums(stickers.size(), vector<int>(26, 0));
        for(int i = 0; i < stickers.size(); i++) {
            for(char c: stickers[i]) nums[i][c-'a']++;
        }
        
        unordered_map<vector<int>, int> mp;
        for(int i = 0; i < 26; i++) {
            for(int j = )
        }
        
    }
    
    vector<int> multiply(vector<int>& a, vector<vector<int>>& b) {
        vector<int> res(26, 0);
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < a.size(); i++) {
                for(int j = 0; j < b.size(); j++) {
                    res[k] += b[j][i]*a[i];
                }
            }
        }
        return res;
    }
    
    bool isLarger(vector<int>& a, vector<int>& b) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] < b[i]) return false;
        }
        return true;
    }
};