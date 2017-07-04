class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int profit = 0, buy = prices[0];
        for(int price: prices) {
            buy = min(buy, price);
            profit = max(profit, price-buy);
        }
        return profit;
    }
};