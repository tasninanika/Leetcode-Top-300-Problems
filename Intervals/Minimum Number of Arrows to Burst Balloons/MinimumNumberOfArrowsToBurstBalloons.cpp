class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int last_end = points[0][1];

        for (const auto& balloon : points) {
            if (balloon[0] > last_end) {
                arrows++;
                last_end = balloon[1];
            }
        }

        return arrows;
    }
};
