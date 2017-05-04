class Solution {
public:
    int myAtoi(string str) {
        int sgn = 1, index = 0; long sum = 0;
        while(str[index] == ' ') index++;
        if(str[index] == '+') sgn = 1;
        else if(str[index] == '-') sgn = -1;
        else if(str[index] >= '0' && str[index] <= '9') sum = str[index] - '0';
        else return 0;
        for(int i = index+1; i < str.size();) {
            while(str[i] >= '0' && str[i] <= '9') {
                sum = sum*10 + str[i] - '0';
                i++;
                if(sum*sgn >= INT_MAX) return INT_MAX;
                if(sum*sgn <= INT_MIN) return INT_MIN;
            }
            break;
        }
        return sum*sgn;
    }
};