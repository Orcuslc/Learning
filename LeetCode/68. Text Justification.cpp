class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        while(i < words.size()) {
            int len = 0, j = 0;
            while(i+j < words.size() && len + words[i+j].size() <= maxWidth - j) {
                len += words[i+(j++)].size();
            }
            j--;
            string tmp = words[i];
            for(int k = 0; k < j; k++) {
                if(i+j >= words.size()-1) tmp += " ";
                else tmp += string((maxWidth-len)/j + (k < (maxWidth-len)%j), ' ');
                tmp += words[i+k+1];
            }
            tmp += string(maxWidth - tmp.size(), ' ');
            res.push_back(tmp);
            i += (j+1);
        }
        return res;
    }
};