class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int>> workers;
        int num_workers = quality.size();

        for (int i = 0; i < num_workers; ++i) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> max_heap;
        int total_quality = 0;
        double min_cost = numeric_limits<double>::max();

        for (const auto& worker : workers) {
            double ratio = worker.first;
            int qual = worker.second;

            total_quality += qual;
            max_heap.push(qual);

            if (max_heap.size() > K) {
                total_quality -= max_heap.top();
                max_heap.pop();
            }

            if (max_heap.size() == K) {
                double cost = ratio * total_quality;
                min_cost = min(min_cost, cost);
            }
        }

        return min_cost;
    }
};
