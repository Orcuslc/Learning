class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        flowerbed.insert(flowerbed.begin(), 0); flowerbed.push_back(0);
        for(int i = 1; i < flowerbed.size()-1; i++) {
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0) {
                count++; i++;
            }
        }
        if(count >= n) return true;
        else return false;
    }
};