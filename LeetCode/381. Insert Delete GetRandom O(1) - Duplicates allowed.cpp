class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = pos.find(val) == pos.end();
        pos[val].emplace_back(nums.size());
        nums.emplace_back(pair<int, int>(val, pos[val].size()-1));
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(pos[val].size() == 0) return false;

        int index = pos[val].back();
        pair<int, int> last = nums.back();
        pos[last.first][last.second] = index;
        nums[index] = last;
        nums.pop_back();
        pos[val].pop_back();

        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
    
private:
    vector<pair<int, int> > nums;
    unordered_map<int, vector<int> > pos;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */