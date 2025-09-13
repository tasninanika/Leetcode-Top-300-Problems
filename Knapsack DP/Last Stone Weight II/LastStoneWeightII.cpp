class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = 0;
        for (int stone : stones) {
            totalSum += stone;
        }

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int stone : stones) {
            for (int j = target; j >= stone; --j) {
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        for (int s1 = target; s1 >= 0; --s1) {
            if (dp[s1]) {
                return totalSum - 2 * s1;
            }
        }

        return 0;
    }
};
