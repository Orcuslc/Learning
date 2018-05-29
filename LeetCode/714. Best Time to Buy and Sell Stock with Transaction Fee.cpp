class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1) return 0;
        int hold[prices.size()] = {0}, no[prices.size()] = {0};
        hold[0] = -prices[0]-fee;
        for(int i = 1; i < prices.size(); i++) {
            hold[i] = max(hold[i-1], no[i-1]-prices[i]-fee);
            no[i] = max(no[i-1], hold[i-1]+prices[i]);
        }
        return max(hold[prices.size()-1], no[prices.size()-1]);
    }
};