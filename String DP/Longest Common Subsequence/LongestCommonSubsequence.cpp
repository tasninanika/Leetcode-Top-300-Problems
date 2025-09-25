class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n + 1, 0), current(n + 1, 0);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    current[j] = 1 + prev[j - 1];
                } else {
                    current[j] = max(prev[j], current[j - 1]);
                }
            }
            swap(prev, current);
        }

        return prev[n];
    }
};
