class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if(findNums.size() == 0) {
            vector<int> res;
            return res;
        }
        unordered_map<int, int> m;
        stack<int> s;
        s.push(-1);
        for(int n : nums) {
            while(n > s.top()) {
                if(s.top() == -1) break;
                else m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        while(!s.empty()) {
            m[s.top()] = -1;
            s.pop();
        }
        
        vector<int> res(findNums.size(), -1);
        for(int i = 0; i < findNums.size(); i++) {
            res[i] = m[findNums[i]];
        }
        return res;
    }
};