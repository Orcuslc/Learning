class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        vector<pair<int, int> > tmp = construct(nums);
        quicksort(tmp, 0, nums.size());
        for(int i = 0; i < nums.size(); i++) {
            pair<int, int> res = bi_search(tmp, i+1, nums.size()-1, target-tmp[i].first);
            if(res.first != -1) {
                indices.push_back(tmp[i].second);
                indices.push_back(res.second);
                return indices;
            }
        }
    }
    
private:
    vector<pair<int, int> > construct(vector<int>& nums) {
        vector<pair<int, int> >tmp;
        for(int i = 0; i < nums.size(); i++) {
            tmp.push_back(make_pair(nums[i], i));
        }
        return tmp;
    }
    bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first <= b.first;
    }
    void swap(pair<int, int> &a, pair<int, int> &b) {
        pair<int, int> t = a;
        a = b;
        b = t;
    }
    int partition(vector<pair<int, int> >& vec, int p, int r) {
        pair<int, int> x = vec[r-1];
        int i = p-1;
        for(int j = p; j < r-1; j++) {
            if(cmp(vec[j], x)) {
                i++;
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i+1], vec[r-1]);
        return i+1;
    }
    void quicksort(vector<pair<int, int> >& vec, int p, int r) {
        if(p < r-1) {
            int q = partition(vec, p, r);
            quicksort(vec, p, q);
            quicksort(vec, q+1, r);
        }
    }
    pair<int, int> bi_search(vector<pair<int, int> >& vec, int start, int end, int val) {
        if(start <= end) {
            int mid = floor((start+end)/2);
            if(vec[mid].first == val) return vec[mid];
            else if(vec[mid].first < val) return bi_search(vec, mid+1, end, val);
            else return bi_search(vec, start, mid-1, val);
        }
        else return make_pair(-1, -1);
    }
};