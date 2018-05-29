class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size()-1; i++) {
            count += search(s, i);
        }
        return count;
    }
    
    int search(string s, int index) {
        int count = (s[index] == '0'? -1: 1), flag = 0, last = s[index];
        for(int i = index+1; i < s.size(); i++) {
            if(count == 0) return 1;
            if(s[i] != last && flag == 1) return 0;
            if(s[i] != last) {
                flag = 1;
                last = s[i];
            }
            count += (s[i] == '0'?-1:1);
        }
        return count == 0;
    }
    
};