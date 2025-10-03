class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> minCut(n, 0);

        for (int i = 0; i < n; ++i) {
            minCut[i] = i;
        }

        for (int mid = 0; mid < n; ++mid) {
            for (int start = mid, end = mid; start >= 0 && end < n && s[start] == s[end]; --start, ++end) {
                minCut[end] = start == 0 ? 0 : min(minCut[end], minCut[start - 1] + 1);
            }
            for (int start = mid, end = mid + 1; start >= 0 && end < n && s[start] == s[end]; --start, ++end) {
                minCut[end] = start == 0 ? 0 : min(minCut[end], minCut[start - 1] + 1);
            }
        }

        return minCut[n - 1];
    }
};
