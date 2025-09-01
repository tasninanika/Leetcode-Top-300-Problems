class Solution {
public:
    vector<int> topSort(int n, vector<int>& indegree, unordered_map<int, vector<int>>& adj) {
        queue<int> q;
        vector<int> order;

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            order.push_back(node);

            for (int neighbor : adj[node]) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return (order.size() == n) ? order : vector<int>();
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int numGroups = m;

        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = numGroups++;
            }
        }

        unordered_map<int, vector<int>> groupGraph, itemGraph;
        vector<int> groupIndegree(numGroups), itemIndegree(n);

        for (int i = 0; i < n; ++i) {
            for (int before : beforeItems[i]) {
                if (group[i] != group[before]) {
                    groupGraph[group[before]].push_back(group[i]);
                    ++groupIndegree[group[i]];
                }

                itemGraph[before].push_back(i);
                ++itemIndegree[i];
            }
        }

        vector<int> groupOrder = topSort(numGroups, groupIndegree, groupGraph);
        vector<int> itemOrder = topSort(n, itemIndegree, itemGraph);

        if (groupOrder.empty() || itemOrder.empty()) {
            return {};
        }

        unordered_map<int, vector<int>> itemsInGroups;
        for (int item : itemOrder) {
            itemsInGroups[group[item]].push_back(item);
        }

        vector<int> result;
        for (int grp : groupOrder) {
            for (int item : itemsInGroups[grp]) {
                result.push_back(item);
            }
        }

        return result;
    }
};
