class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        return dfs(bits, 0);
    }
    
    bool dfs(vector<int>& bits, int index) {
        if(index == bits.size()) return false;
        if(index == bits.size()-1) {
            if(bits.back() == 0) return true;
            else return false;
        }
        if(bits[index] == 0) return dfs(bits, index+1);
        else return dfs(bits, index+2);
    }
};