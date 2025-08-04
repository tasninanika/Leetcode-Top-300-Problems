class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.push_back({Capital[i], Profits[i]});
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;
        int i = 0;

        for (int j = 0; j < k; ++j) {
            while (i < n && projects[i].first <= W) {
                maxHeap.push(projects[i].second);
                i++;
            }
            if (maxHeap.empty()) break;

            W += maxHeap.top();
            maxHeap.pop();
        }

        return W;
    }
};
