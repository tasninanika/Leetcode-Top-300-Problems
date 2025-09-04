class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        pq.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            auto [max_elevation, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == n - 1) {
                return max_elevation;
            }

            for (auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.emplace(max(max_elevation, grid[nx][ny]), nx, ny);
                }
            }
        }
        return -1;
    }
};
