class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1] - heights[i];

            if (diff > 0) {
                pq.push(diff);
                bricks -= diff;

                if (bricks < 0) {
                    bricks += pq.top();
                    pq.pop();
                    ladders--;

                    if (ladders < 0) {
                        return i;
                    }
                }
            }
        }
        return heights.size() - 1;
    }

};
