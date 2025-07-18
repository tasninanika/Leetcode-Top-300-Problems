class Solution {
public:
    void precomputePalindromes(string &s, vector<vector<bool>> &dp) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i+1 < n; i++) {
            dp[i][i+1] = (s[i] == s[i+1]);
        }
        for (int length = 3; length <= n; length++) {
            for (int i = 0; i <= n-length; i++) {
                int j = i + length - 1;
                dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
            }
        }
    }

    void backtrack(int start, string &s, vector<string> &current, vector<vector<string>> &result, vector<vector<bool>> &dp) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (dp[start][end]) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, current, result, dp);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        precomputePalindromes(s, dp);

        vector<vector<string>> result;
        vector<string> current;
        backtrack(0, s, current, result, dp);
        return result;
    }
};
