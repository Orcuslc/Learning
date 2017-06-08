class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_set<char> r1 = {'q', 'w', 'e', 'r', 't', 'y','u', 'i', 'o', 'p'};
        unordered_set<char> r2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'}; 
        unordered_set<char> r3 = {'z', 'x', 'c', 'v', 'b' ,'n', 'm'};
        vector<unordered_set<char>> rows = {r1, r2, r3};
        for(int i = 0; i < words.size(); i++) {
            int row = 0, flag = 1;
            for(int j = 0; j < 3; j++) {
                if(rows[j].count((char)tolower(words[i][0])) > 0) {
                    row = j;
                    break;
                }
            }
            for(int k = 1; k < words[i].size(); k++) {
                if(rows[row].count((char)tolower(words[i][k])) == 0) {
                    flag = 0;
                    break;
                }
            }
            if(flag) res.push_back(words[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        map<char, int> mp;
        mp['q'] = 1; mp['w'] = 1; mp['e'] = 1; mp['r'] = 1; mp['t'] = 1; mp['y'] = 1; mp['u'] = 1; mp['i'] = 1; mp['o'] = 1; mp['p'] = 1;
        mp['a'] = 2; mp['s'] = 2; mp['d'] = 2; mp['f'] = 2; mp['g'] = 2; mp['h'] = 2; mp['j'] = 2; mp['k'] = 2; mp['l'] = 2;
        mp['z'] = 3; mp['x'] = 3; mp['c'] = 3; mp['v'] = 3; mp['b'] = 3; mp['n'] = 3; mp['m'] = 3;
        for(int i = 0; i < words.size(); i++) {
            int set = mp[(char)tolower(words[i][0])], flag = 1;
            for(int j = 1; j < words[i].length(); j++) {
                if(mp[(char)tolower(words[i][j])] != set) {
                    flag = 0;
                    break;
                }
            }
            if(flag) res.push_back(words[i]);
        }
        return res;
    }
};