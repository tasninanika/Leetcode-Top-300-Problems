class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int time = 0, i = 0;
        vector<int> result;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> available;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> busy;

        for (int i = 0; i < n; ++i) {
            available.push({servers[i], i});
        }

        while (i < tasks.size()) {
            time = max(time, i);

            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [endTime, weight, index] = busy.top();
                busy.pop();
                available.push({weight, index});
            }

            if (available.empty()) {
                time = get<0>(busy.top());
                while (!busy.empty() && get<0>(busy.top()) == time) {
                    auto [endTime, weight, index] = busy.top();
                    busy.pop();
                    available.push({weight, index});
                }
            }

            auto [weight, index] = available.top(); available.pop();
            result.push_back(index);
            busy.push({time + tasks[i], weight, index});
            ++i;
        }

        return result;
    }
};

