class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string> s;
        for(string::iterator it = preorder.begin(); it != preorder.end();) {
            string::iterator it2 = it;
            while(it2 != preorder.end() && *it2 != ',') it2++;
            string tmp(it, it2);
            it = it2;
            if(it2 != preorder.end()) it++;
            while(tmp == "#" && !s.empty() && s.top() == "#") {
                s.pop();
                if(s.empty()) return false;
                s.pop();
            }
            s.push(tmp);
        }
        return s.size() == 1 && s.top() == "#";
    }
};