class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(!heights.size()) return 0;
        int dp[heights.size()][heights.size()]; // dp[i][j]: largest height of rectangles starting with i, ending with j;
        int maxArea = INT_MIN;
        for(int i = 0; i < heights.size(); i++) {
            dp[i][i] = heights[i];
            if(heights[i] > maxArea) maxArea = heights[i];
        }
        for(int j = 1; j < heights.size(); j++) {
            for(int i = j-1; i >= 0; i--) {
                dp[i][j] = min(dp[i+1][j], heights[i]);
                int area = (j-i+1)*dp[i][j];
                if(area > maxArea) maxArea = area;
            }
        }
        return maxArea;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0); heights.push_back(0);
        stack<int> s; s.push(0);
        int res = 0, index = 0;
        for(int i = 1; i < heights.size(); i++) {
            while(heights[i] < heights[s.top()]) {
                index = s.top(); s.pop();
                res = max(res, heights[index]*(i-s.top()-1));
            }
            s.push(i);
        }
        heights.erase(heights.begin()); heights.pop_back(); // 还原输入
        return res;
    }
};