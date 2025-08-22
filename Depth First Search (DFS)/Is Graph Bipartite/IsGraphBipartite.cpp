class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int currentColor) {
        color[node] = currentColor;

        for (int adjacent : graph[node]) {
            if (color[adjacent] == -1) {
                if (!dfs(graph, color, adjacent, 1 - currentColor)) {
                    return false;
                }
            }
            else if (color[adjacent] == color[node]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                if (!dfs(graph, color, i, 0)) {
                    return false;
                }
            }
        }
        return true;
    }
};
