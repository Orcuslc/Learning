class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word == "") return true;
        bool flag = word[0] < 'a';
        int upper = flag?1:0;
        for(int i = 1; i < word.size(); i++) {
            if(flag) {
                flag = word[i] < 'a';
                if(!flag) {
                    if(upper > 1) return false;
                }
                upper++;
            }
            else {
                bool local = word[i] < 'a';
                if(local) return false;
                flag = local;
            }
        }
        return true;
    }
};