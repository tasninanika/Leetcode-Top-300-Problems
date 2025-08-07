class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto partition = [&points](int left, int right) {
            int pivot_distance = points[right][0] * points[right][0] + points[right][1] * points[right][1];
            int store_index = left;
            for (int i = left; i < right; ++i) {
                if ((points[i][0] * points[i][0] + points[i][1] * points[i][1]) <= pivot_distance) {
                    std::swap(points[i], points[store_index]);
                    ++store_index;
                }
            }
            std::swap(points[store_index], points[right]);
            return store_index;
        };

        int left = 0, right = points.size() - 1;
        while (left <= right) {
            int pivot_index = partition(left, right);
            if (pivot_index == K - 1) {
                break;
            }
            if (pivot_index < K - 1) {
                left = pivot_index + 1;
            } else {
                right = pivot_index - 1;
            }
        }

        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
