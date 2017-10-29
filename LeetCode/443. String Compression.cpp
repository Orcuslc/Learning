class Solution {
public:
    int compress(vector<char>& chars) {
        if(!chars.size()) return 0;
        int i = chars.size()-2, local = 1;
        char last = chars.back();
        while(i >= 0) {
            if(chars[i] != last) {
                if(local == 1) {
                    last = chars[i];
                    i--;
                    local = 1;
                    continue;
                }
                else {
                    chars.erase(chars.begin()+i+2, chars.begin()+i+local+1);
                    while(local) {
                        char c = local%10 + '0';
                        local /= 10;
                        chars.insert(chars.begin()+i+2, c);
                    }
                }
                last = chars[i];
                local = 1;
            }
            else {
                local++;
            }
            i--;
        }
        if(local != 1) {
            chars.erase(chars.begin()+1, chars.begin()+local);
            while(local) {
                char c = local%10 + '0';
                local /= 10;
                chars.insert(chars.begin()+1, c);
            }
        }
        return chars.size();
    }
};