class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        int n = prices.size();
        vector<int> held(n, 0), sold(n, 0), rest(n, 0);
    }
};
