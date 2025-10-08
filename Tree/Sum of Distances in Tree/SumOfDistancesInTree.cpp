class Solution {
public:
    void dfs1(int node, int parent, vector<vector<int>> &graph, vector<int> &count, vector<int> &dist) {
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs1(neighbor, node, graph, count, dist);
                count[node] += count[neighbor];
                dist[node] += dist[neighbor] + count[neighbor];
            }
        }
        count[node] += 1;
    }

    void dfs2(int node, int parent, vector<vector<int>> &graph, vector<int> &count, vector<int> &dist, vector<int> &result, int N) {
        result[node] = dist[node];

        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                int originalDistNode = dist[node];
                int originalDistNeighbor = dist[neighbor];
                int originalCountNeighbor = count[neighbor];

                dist[node] -= dist[neighbor] + count[neighbor];
                count[node] -= count[neighbor];
                dist[neighbor] += dist[node] + count[node];
                count[neighbor] += count[node];

                dfs2(neighbor, node, graph, count, dist, result, N);

                count[neighbor] = originalCountNeighbor;
                dist[neighbor] = originalDistNeighbor;
                count[node] += originalCountNeighbor;
                dist[node] = originalDistNode;
            }
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> graph(N);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> result(N, 0);
        vector<int> count(N, 0);
        vector<int> dist(N, 0);

        dfs1(0, -1, graph, count, dist);
        dfs2(0, -1, graph, count, dist, result, N);

        return result;
    }

};
