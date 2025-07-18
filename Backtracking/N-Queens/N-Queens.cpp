class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0), d1(2 * n, 0), d2(2 * n, 0);

        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                solutions.push_back(board);
                return;
            }

            for (int col = 0; col < n; ++col) {
                if (cols[col] || d1[row - col + n] || d2[row + col]) continue;

                board[row][col] = 'Q';
                cols[col] = d1[row - col + n] = d2[row + col] = 1;

                backtrack(row + 1);

                board[row][col] = '.';
                cols[col] = d1[row - col + n] = d2[row + col] = 0;
            }
        };

        backtrack(0);
        return solutions;
    }
};
