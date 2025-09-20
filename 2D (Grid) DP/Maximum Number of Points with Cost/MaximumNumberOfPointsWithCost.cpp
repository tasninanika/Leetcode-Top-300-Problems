class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();

        vector<long long> dp(cols, 0);

        for (int j = 0; j < cols; j++) {
            dp[j] = points[0][j];
        }

        for (int i = 1; i < rows; i++) {
            vector<long long> left(cols, 0);
            vector<long long> right(cols, 0);
