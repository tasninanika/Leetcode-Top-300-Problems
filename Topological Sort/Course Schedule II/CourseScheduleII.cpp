class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for (const auto& pair : prerequisites) {
            adjList[pair[1]].push_back(pair[0]);
        }

        vector<int> visited(numCourses, 0);
        stack<int> orderStack;
        bool possible = true;

        function<void(int)> dfs = [&](int node) {
            if (!possible) return;

            visited[node] = 1;
            for (int neighbor : adjList[node]) {
                if (visited[neighbor] == 0) {
                    dfs(neighbor);
                } else if (visited[neighbor] == 1) {
                    possible = false;
                }
            }
            visited[node] = 2;
            orderStack.push(node);
        };

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0 && possible) {
                dfs(i);
            }
        }

        if (!possible) return {};

        vector<int> order;
        while (!orderStack.empty()) {
            order.push_back(orderStack.top());
            orderStack.pop();
        }

        return order;
    }
};
