class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> outDegree(n, 0);

        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                reverseGraph[v].push_back(u);
                outDegree[u]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (outDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;
        vector<bool> isSafe(n, false);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            isSafe[node] = true;

            for (int precursor : reverseGraph[node]) {
                outDegree[precursor]--;
                if (outDegree[precursor] == 0) {
                    q.push(precursor);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (isSafe[i]) {
                safeNodes.push_back(i);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
