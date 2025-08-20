class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        stack<pair<int, vector<int>>> s;
        s.push({0, {0}});

        while (!s.empty()) {
            auto [node, path] = s.top();
            s.pop();

            if (node == graph.size() - 1) {
                result.push_back(path);
            } else {
                for (int nextNode : graph[node]) {
                    vector<int> newPath = path;
                    newPath.push_back(nextNode);
                    s.push({nextNode, newPath});
                }
            }
        }

        return result;
    }
};

