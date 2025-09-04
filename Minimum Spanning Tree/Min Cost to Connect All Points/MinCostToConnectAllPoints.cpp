class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<bool> inMST(n, false);

        minHeap.push({0, 0});
        int totalCost = 0;
        int edgesUsed = 0;

        while (edgesUsed < n && !minHeap.empty()) {
            auto [cost, u] = minHeap.top();
            minHeap.pop();

            if (inMST[u]) continue;

            inMST[u] = true;
            totalCost += cost;
            edgesUsed++;

            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int nextCost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minHeap.push({nextCost, v});
                }
            }
        }

        return totalCost;
    }
};
