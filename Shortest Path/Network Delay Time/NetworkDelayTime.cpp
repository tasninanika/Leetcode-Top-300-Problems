class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n + 1, numeric_limits<int>::max());
        distance[k] = 0;

        for (int i = 0; i < n - 1; ++i) {
            for (auto& edge : times) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (distance[i] == numeric_limits<int>::max())
                return -1;
            maxTime = max(maxTime, distance[i]);
        }

        return maxTime;
    }
};
