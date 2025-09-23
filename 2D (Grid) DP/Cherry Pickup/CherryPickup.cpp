class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, dp(grid, memo, 0, 0, 0, n));
    }

private:
    int dp(vector<vector<int>>& grid, vector<vector<vector<int>>>& memo, int r1, int c1, int c2, int n) {
        int r2 = r1 + c1 - c2;

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }

        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        if (memo[r1][c1][c2] != INT_MIN) {
            return memo[r1][c1][c2];
        }

        int cherries = grid[r1][c1];
        if (c1 != c2) {
            cherries += grid[r2][c2];
        }

        cherries += max({dp(grid, memo, r1 + 1, c1, c2, n),
                         dp(grid, memo, r1, c1 + 1, c2, n),
                         dp(grid, memo, r1 + 1, c1, c2 + 1, n),
                         dp(grid, memo, r1, c1 + 1, c2 + 1, n)});

        memo[r1][c1][c2] = cherries;
        return cherries;
    }
};
