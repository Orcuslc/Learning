class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st; // scores;
        for(string s: ops) {
            if(s == "C") st.pop();
            else if(s == "D") st.push(st.top()*2);
            else if(s == "+") {
                int x1 = st.top(); st.pop();
                int x2 = st.top();
                st.push(x1); st.push(x1+x2);
            }
            else st.push(stoi(s));
        }
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};