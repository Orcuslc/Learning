class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mpN, mpM;
        for(auto i: ransomNote) mpN[i]++;
        for(auto i: magazine) mpM[i]++;
        for(char i = 'a'; i <= 'z'; i++) if(mpN[i] > mpM[i]) return false;
        return true;
    }
};