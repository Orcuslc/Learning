class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Assume we start at 0, if it can not travel around, then there exist a p, and the car can visit p, but can't reach p+1; then Any Nodes before p are not available as a start;
        int start = 0, n = gas.size(), j;
        for(int i = 0; i < n; i += j) {
            int sum = 0;
            for(j = 1; j <= n; j++) {
                int k = (i+j-1)%n;
                sum += gas[k]-cost[k];
                if(sum < 0) break;
            }
            if(j > n) return i;
        }
        return -1;
    }
};