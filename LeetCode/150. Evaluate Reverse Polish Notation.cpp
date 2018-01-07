class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string c: tokens) {
            if(!isOp(c)) s.push(stoi(c));
            else {
                int n2 = s.top(); s.pop();
                int n1 = s.top(); s.pop();
                if(c == "-") s.push(n1-n2);
                else if(c == "*") s.push(n1*n2);
                else if(c == "+") s.push(n1+n2);
                else if(c == "/") s.push(n1/n2);
            }
        }
        return s.top();
    }
    
    bool isOp(string s) {
        return s == "-" || s == "+" || s == "*" || s == "/";
    }
};