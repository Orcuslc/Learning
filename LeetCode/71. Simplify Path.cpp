class Solution {
public:
    string simplifyPath(string path) {
        vector<string> s;
        string res, tmp;
        stringstream ss(path);
        while(getline(ss, tmp, '/')) {
            if(tmp == "" || tmp == ".") continue;
            if(tmp == ".." && !s.empty()) s.pop_back();
            else if(tmp != "..") s.push_back(tmp);
        }
        for(string c: s) res += "/"+c;
        return !res.size() ? "/":res;
    }
};