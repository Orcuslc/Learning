class Solution {
public:
    string getPermutation(int n, int k) {
        int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<int> nums;
        for(int i = 1; i <= n; i++) nums.push_back(i);
        string res = "";
        for(int i = 1; i <= n; i++) {
            int index = (k-1)/factorials[n-i];
            res += to_string(nums[index]);
            nums.erase(nums.begin()+index);
            k -= index*factorials[n-i];
        }
        return res;
    }
};