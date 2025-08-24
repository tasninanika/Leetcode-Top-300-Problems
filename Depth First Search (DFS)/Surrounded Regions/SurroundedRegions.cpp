class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();

        auto dfs = [&](int x, int y, auto&& dfs_ref) -> void {
            if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
                return;
            }
            board[x][y] = 'T';

            dfs_ref(x + 1, y, dfs_ref);
            dfs_ref(x - 1, y, dfs_ref);
            dfs_ref(x, y + 1, dfs_ref);
            dfs_ref(x, y - 1, dfs_ref);
        };

        for (int i = 0; i < m; ++i) {
            dfs(i, 0, dfs);
            dfs(i, n - 1, dfs);
        }
        for (int j = 0; j < n; ++j) {
            dfs(0, j, dfs);
            dfs(m - 1, j, dfs);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
