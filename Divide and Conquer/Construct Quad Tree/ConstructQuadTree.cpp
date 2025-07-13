class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, 0, grid.size());
    }

    Node* construct(vector<vector<int>>& grid, int x, int y, int length) {
        if (length == 1) {
            return new Node(grid[x][y] == 1, true);
        }

        int half = length / 2;
        Node* topLeft = construct(grid, x, y, half);
        Node* topRight = construct(grid, x, y + half, half);
        Node* bottomLeft = construct(grid, x + half, y, half);
        Node* bottomRight = construct(grid, x + half, y + half, half);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
            return new Node(topLeft->val, true);
        }
        else {
            return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
        }
    }
};
