class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        int numbers[n]; numbers[0] = 1;
        int pos[primes.size()]; memset(pos, 0, sizeof(pos));
        for(int i = 1; i < n; i++) {
            int Min = INT_MAX;
            for(int j = 0; j < primes.size(); j++) {
                if(numbers[pos[j]]*primes[j] < Min) {
                    Min = numbers[pos[j]]*primes[j];
                }
            }
            numbers[i] = Min;
            for(int j = 0; j < primes.size(); j++) {
                if(numbers[i] == numbers[pos[j]]*primes[j])
                    pos[j]++;
            }
        }
        return numbers[n-1];
    }
};