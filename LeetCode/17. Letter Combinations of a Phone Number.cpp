class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        vector<string> s = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        res.push_back("");
        for(int i = 0; i < digits.size(); i++){
            int index = digits[i] - '0';
            string letters = s[index];
            if(letters.empty()) continue;
            vector<string> tmp;
            for(int j = 0; j < res.size(); j++) {
                for(int k = 0; k < letters.size(); k++) {
                    tmp.push_back(res[j]+letters[k]);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};