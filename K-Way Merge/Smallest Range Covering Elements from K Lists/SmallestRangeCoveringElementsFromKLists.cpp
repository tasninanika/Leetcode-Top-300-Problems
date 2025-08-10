struct Node {
    int value;
    int row;
    int idx;
    bool operator>(const Node& other) const {
        return value > other.value;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int minRange = INT_MAX;
        int currentMax = INT_MIN;

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }

        int start = 0, end = 0;

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            int currentRange = currentMax - curr.value;
            if (currentRange < minRange) {
                minRange = currentRange;
                start = curr.value;
                end = currentMax;
            }

            if (curr.idx + 1 < nums[curr.row].size()) {
                int nextValue = nums[curr.row][curr.idx + 1];
                pq.push({nextValue, curr.row, curr.idx + 1});
                currentMax = max(currentMax, nextValue);
            }
            else {
                break;
            }
        }

        return {start, end};
    }
};
