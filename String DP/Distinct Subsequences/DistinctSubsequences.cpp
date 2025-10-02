class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return countSubsequences(s, t, 0, 0, dp);
    }

private:
    int countSubsequences(const string &s, const string &t, int i, int j, vector<vector<int>>& dp) {
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            dp[i][j] = countSubsequences(s, t, i + 1, j + 1, dp) + countSubsequences(s, t, i + 1, j, dp);
        }
        else {
            dp[i][j] = countSubsequences(s, t, i + 1, j, dp);
        }
        return dp[i][j];
    }
};
