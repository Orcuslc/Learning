/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> st; st.push(NestedInteger());
        for(int i = 0; i < s.size(); i++) {
            if(isNum(s[i])) {
                int num = 0, sgn = 1;
                if(s[i] == '-') {
                    sgn = -1;
                    i++;
                }
                while(isNum(s[i])) {
                    num = num*10+s[i]-'0';
                    i++;
                }
                num *= sgn;
                st.top().add(NestedInteger(num));
                i--;
            }
            else {
                if(s[i] == '[') st.push(NestedInteger());
                else if(s[i] == ']') {
                    NestedInteger tmp = st.top(); st.pop();
                    st.top().add(tmp);
                }
            }
        }
        NestedInteger res = st.top().getList().front();
        return res;
    }
    
    bool isNum(char c) {
        return c == '-' || isdigit(c);
    }
};