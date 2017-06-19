class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s), res;
        string buf;
        while(ss >> buf) {
            string rev(buf.rbegin(), buf.rend());
            res << rev << ' ';
        }
        return res.str().substr(0, res.str().length()-1);
    }
};