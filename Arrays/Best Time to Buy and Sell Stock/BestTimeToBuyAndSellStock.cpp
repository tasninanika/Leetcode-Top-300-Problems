class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumPrice = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - minimumPrice);
            minimumPrice = min(minimumPrice, prices[i]);
        }

        return profit;

    }
};

