class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> area(n * n + 2, 0);
        int id = 2;
        int best = 0;

        function<int(int,int)> dfs = [&](int r, int c) -> int {
            if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) return 0;
            grid[r][c] = id;
            return 1 + dfs(r+1, c) + dfs(r-1, c) + dfs(r, c+1) + dfs(r, c-1);
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int a = dfs(i, j);
                    area[id] = a;
                    best = max(best, a);
                    ++id;
                }
            }
        }

        bool hasZero = false;
        int dirs[5] = {-1, 0, 1, 0, -1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    hasZero = true;
                    unordered_set<int> seen;
                    int sum = 1;
                    for (int d = 0; d < 4; ++d) {
                        int ni = i + dirs[d], nj = j + dirs[d+1];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                        int nid = grid[ni][nj];
                        if (nid >= 2 && seen.insert(nid).second) {
                            sum += area[nid];
                        }
                    }
                    best = max(best, sum);
                }
            }
        }

        return hasZero ? best : n * n;
    }
};
