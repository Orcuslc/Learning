class Solution {
public:
    string originalDigits(string s) {
        if(!s.size()) return "";
        
        int count[128];
        memset(count, 0, sizeof(count));
        for(char c: s) count[c]++;
        
        int num[10]; 
        memset(num, 0, sizeof(num));
        num[0] = count['z'];
        num[2] = count['w'];
        num[4] = count['u'];
        num[6] = count['x'];
        num[8] = count['g'];
        num[1] = count['o']-count['z']-count['w']-count['u'];
        num[3] = count['h']-count['g'];
        num[5] = count['v']-count['s']+count['x'];
        num[7] = count['s']-count['x'];
        num[9] = count['i']-count['x']-count['g']-count['v']+count['s']-count['x'];
        
        string res = "";
        for(int i = 0; i < 10; i++) {
            for(int j = num[i]; j > 0; j--) res += to_string(i);
        }
        return res;
    }
};