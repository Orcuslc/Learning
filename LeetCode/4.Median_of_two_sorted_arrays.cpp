class Solution {
    // 维护两个长度相等的部分, 每次搜索时把一个数从一个部分移至另一个部分, 再进行二分查找
    // 这两个部分满足: 左边部分的最大值小于等于右边部分的最小值
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) return _find(nums2, nums1, n, m);
        else return _find(nums1, nums2, m, n);
    }
    
private:
    double _find(vector<int>& nums1, vector<int>& nums2, int m, int n) { // m <= n
        int start = 0, end = m, mid = (m+n+1)/2;
        double left_max, right_min;
        while(start <= end) {
            int i = (start+end)/2;
            int j = mid - i;
            if(i < m && nums2[j-1] > nums1[i]) start = i+1;
            else if(i > 0 && nums2[j] < nums1[i-1]) end = i-1;
            else {
                if(i == 0) left_max = nums2[j-1];
                else if(j == 0) left_max = nums1[i-1];
                else left_max = max(nums1[i-1], nums2[j-1]);
                if(i == m) right_min = nums2[j];
                else if(j == n) right_min = nums1[i];
                else right_min = min(nums1[i], nums2[j]);
                if((m+n)%2 == 1) return left_max;
                else return (left_max+right_min)/2;
            }
        }
    }
};