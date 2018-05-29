class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        int res = 0; string tmp;
        while(ss >> tmp) res++;
        return res;
    }
};

class Solution {
public:
    int countSegments(string s) {
        int count = 0, isalpha = false;
        for(char i : s) {
            if(i != ' ') {
                if(isalpha) continue;
                else isalpha = true;
            }
            else {
                if(isalpha) {
                    count++;
                    isalpha = false;
                }
                else continue;
            }
        }
        if(isalpha) count++;
        return count;
    }
};