class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int start, int target) {
        if (start == target) return 0;

        unordered_map<int, vector<int>> stop_to_routes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stop_to_routes[stop].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        unordered_set<int> visited;

        for (int route : stop_to_routes[start]) {
            q.push({route, 1});
            visited.insert(route);
        }

        while (!q.empty()) {
            auto [current_route, buses] = q.front();
            q.pop();

            for (int stop : routes[current_route]) {
                if (stop == target) return buses;
                for (int route_next : stop_to_routes[stop]) {
                    if (visited.find(route_next) == visited.end()) {
                        q.push({route_next, buses + 1});
                        visited.insert(route_next);
                    }
                }
            }
        }

        return -1;
    }
};
