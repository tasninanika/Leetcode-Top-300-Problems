class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        int n = prices.size();
        vector<int> held(n, 0), sold(n, 0), rest(n, 0);

        held[0] = -prices[0];
        sold[0] = 0;
        rest[0] = 0;
    }
};
