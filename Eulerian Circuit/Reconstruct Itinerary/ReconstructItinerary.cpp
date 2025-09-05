class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;

        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        vector<string> itinerary;
        stack<string> dfs_stack;
        dfs_stack.push("JFK");

        while (!dfs_stack.empty()) {
            string current = dfs_stack.top();

            if (graph[current].empty()) {
                itinerary.push_back(current);
                dfs_stack.pop();
            } else {
                auto next = *(graph[current].begin());
                graph[current].erase(graph[current].begin());
                dfs_stack.push(next);
            }
        }

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
