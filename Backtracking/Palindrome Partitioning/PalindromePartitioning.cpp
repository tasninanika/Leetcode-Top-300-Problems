class Solution {
public:
    vector<vector<string>> partition(string s) {
       int n = s.size();
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int i = 0; i+1 < n; ++i) {
            dp[i][i+1] = (s[i] == s[i+1]);
        }
        for (int length = 3; length <= n; ++length) {
            for (int i = 0; i <= n-length; ++i) {
                int j = i + length - 1;
                dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
            }
        }
    }
};
