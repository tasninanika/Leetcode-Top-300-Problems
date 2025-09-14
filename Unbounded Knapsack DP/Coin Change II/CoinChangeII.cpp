class Solution {
public:
    int dp[301][5001];

    int coinChange(int amount, vector<int>& coins, int index) {
        if (amount == 0) return 1;
        if (amount < 0 || index >= coins.size()) return 0;
        if (dp[index][amount] != -1) return dp[index][amount];

        int include = coinChange(amount - coins[index], coins, index);
        int exclude = coinChange(amount, coins, index + 1);

        return dp[index][amount] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return coinChange(amount, coins, 0);
    }
};
