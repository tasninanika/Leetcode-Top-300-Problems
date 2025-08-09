class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int prev_end = intervals[0][1];
        int count = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev_end) {
                ++count;
            }
            else {
                prev_end = intervals[i][1];
            }
        }

        return count;
    }
};
