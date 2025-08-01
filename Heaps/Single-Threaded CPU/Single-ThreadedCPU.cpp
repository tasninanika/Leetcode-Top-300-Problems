class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> indexedTasks;
        for (int i = 0; i < n; i++) {
            indexedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(indexedTasks.begin(), indexedTasks.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result;
        long long currTime = 0;
        int index = 0;

        while (index < n || !pq.empty()) {
            while (index < n && indexedTasks[index][0] <= currTime) {
                pq.push({indexedTasks[index][1], indexedTasks[index][2]});
                index++;
            }

            if (!pq.empty()) {
                auto [processingTime, taskIndex] = pq.top();
                pq.pop();
                currTime += processingTime;
                result.push_back(taskIndex);
            } else if (index < n) {
                currTime = indexedTasks[index][0];
            }
        }

        return result;
    }
};

