class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> process; process.insert(n);
        int next;
        while(1) {
            next = happy(n);
            if(next == 1) return true;
            else if(process.find(next) != process.end()) return false;
            process.insert(next);
            n = next;
        }
    }
    
    int happy(int n) {
        int count = 0;
        while(n) {
            count += (n%10)*(n%10);
            n /= 10;
        }
        return count;
    }
};