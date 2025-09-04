class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        const vector<int> directions = {-1, 0, 1, 0, -1};

        pq.emplace(0, 0, 0);
        effort[0][0] = 0;

        while (!pq.empty()) {
            auto [currEffort, x, y] = pq.top();
            pq.pop();

            if (x == rows - 1 && y == cols - 1) {
                return currEffort;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i];
                int ny = y + directions[i + 1];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols) {
                    int nextEffort = max(currEffort, abs(heights[nx][ny] - heights[x][y]));
                    if (nextEffort < effort[nx][ny]) {
                        effort[nx][ny] = nextEffort;
                        pq.emplace(nextEffort, nx, ny);
                    }
                }
            }
        }

        return 0;
    }
};
