class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int res = 0, local = 0;
        vector<int> letters(26, 0); // number of strings starting with each letter
        for(int i = 0; i < p.size(); i++) {
            int letter = p[i] - 'a';
            if(i > 0 && (p[i-1] - 'a') != (letter+25)%26) local = 0;
            local++;
            if(local > letters[letter]) {
                res += (local - letters[letter]);
                letters[letter] = local;
            }
        }
        return res;
    }
};