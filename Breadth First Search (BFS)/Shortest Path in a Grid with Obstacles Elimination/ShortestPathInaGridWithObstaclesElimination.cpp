class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        queue<tuple<int, int, int, int>> q;
        q.push({0, 0, 0, 0});

        while (!q.empty()) {
            auto [x, y, steps, eliminated] = q.front();
            q.pop();

            if (x == n - 1 && y == m - 1) {
                return steps;
            }

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newEliminated = eliminated + grid[nx][ny];

                    if (newEliminated <= k && !visited[nx][ny][newEliminated]) {
                        visited[nx][ny][newEliminated] = true;
                        q.push({nx, ny, steps + 1, newEliminated});
                    }
                }
            }
        }

        return -1;
    }
};
