class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int cols = points[0].size();

        vector<long long> dp(cols, 0);
