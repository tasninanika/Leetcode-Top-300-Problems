class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int length = 2; length <= n + 1; ++length) {
            for (int left = 0; left <= n + 1 - length; ++left) {
                int right = left + length;
                for (int i = left + 1; i < right; ++i) {
                    dp[left][right] = max(dp[left][right],
                                          nums[left] * nums[i] * nums[right]
                                          + dp[left][i] + dp[i][right]);
                }
            }
        }

        return dp[0][n + 1];
    }
};
