class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> rottenQueue;
        int freshCount = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) {
                    rottenQueue.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) {
            return 0;
        }

        int minutes = 0;

        while (!rottenQueue.empty()) {
            int size = rottenQueue.size();
            bool rotted = false;

            for (int i = 0; i < size; ++i) {
                auto [row, col] = rottenQueue.front();
                rottenQueue.pop();

                for (auto [dr, dc] : directions) {
                    int newRow = row + dr, newCol = col + dc;

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        rottenQueue.push({newRow, newCol});
                        freshCount--;
                        rotted = true;
                    }
                }
            }

            if (rotted) {
                minutes++;
            }
        }

        return (freshCount == 0) ? minutes : -1;
    }
};
