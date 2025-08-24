class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        queue<pair<int, int>> pq, aq;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int i = 0; i < m; ++i) {
            pq.push({i, 0});
            aq.push({i, n - 1});
            pacific[i][0] = true;
            atlantic[i][n - 1] = true;
        }
        for (int j = 0; j < n; ++j) {
            pq.push({0, j});
            aq.push({m - 1, j});
            pacific[0][j] = true;
            atlantic[m - 1][j] = true;
        }

        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& ocean){
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : dir) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                        ocean[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        };

        bfs(pq, pacific);
        bfs(aq, atlantic);

        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
