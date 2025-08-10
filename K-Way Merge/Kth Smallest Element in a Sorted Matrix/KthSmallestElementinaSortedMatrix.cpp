class Solution {
public:
    struct Element {
        int value, row, col;
        bool operator>(const Element& other) const {
            return value > other.value;
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<Element, vector<Element>, greater<Element>> minHeap;

        for (int row = 0; row < n; ++row) {
            minHeap.push({matrix[row][0], row, 0});
        }

        for (int i = 0; i < k - 1; ++i) {
            Element current = minHeap.top();
            minHeap.pop();

            if (current.col < n - 1) {
                minHeap.push({matrix[current.row][current.col + 1], current.row, current.col + 1});
            }
        }

        return minHeap.top().value;
    }
};
