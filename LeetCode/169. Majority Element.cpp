class Solution {
public:
    int majorityElement(vector<int>& nums) {    
        int res = nums[0], count = 1;
        for(int i: nums) {
            i == res? count++: count--;
            if(count == 0) {
                res = i;
                count = 1;
            }
        }
        return res;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {    
        unordered_map<int, int> mp;
        int size = nums.size()/2;
        for(int i: nums) if(++mp[i] > size) return i;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        srand(unsigned(time(NULL)));
        while(1) {
            int index = rand() % size;
            int sample = nums[index];
            int count = 0;
            for(int i: nums) {
                if(sample == i) count++;
            }
            if(count > size/2) return sample;
        }
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return recursion(nums, 0, nums.size()-1);
    }
    
    int recursion(vector<int>& nums, int left, int right) {
        if(left == right) return nums[left];
        int mid = (left+right)/2;
        int l = recursion(nums, left, mid), r = recursion(nums, mid+1, right);
        if(l == r) return l;
        else return count(nums.begin()+left, nums.begin()+right+1, l) > count(nums.begin()+left, nums.begin()+right+1, r)? l:r;
    }
};