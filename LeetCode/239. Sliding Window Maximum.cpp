class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(!nums.size() || k <= 0) return vector<int>();
        int n = nums.size();
        vector<int> res(n-k+1, 0);
        int index = 0;
        deque<int> q;
        for(int i = 0; i < n; i++) {
            while(!q.empty() && q.front() < i-k+1) q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if(i >= k-1) res[index++] = nums[q.front()];
        }
        return res;
    }
};