class Solution {
public:
    int maxArea(vector<int>& height) {
        // Area = abs(j-i)/2*min(a[i), a[j])
        int i = 0, j = height.size()-1; // 从最大底边开始搜索
        int MAX = 0;
        // 不妨设min(a[i], a[j]) = a[i], 那么min(a[i], a[k]) <= a[i], for each k;
        while(i < j) {
            MAX = max(MAX, (j-i)*min(height[i], height[j]));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return MAX;
    }
};