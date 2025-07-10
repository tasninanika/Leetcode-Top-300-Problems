class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap;
        int maxValue = INT_MIN;

        for(const auto& point : points){
            int xj = point[0], yj = point[1];

            while(!maxHeap.empty() && (xj - maxHeap.top().second > k)){
                maxHeap.pop();
            }

            if(!maxHeap.empty()){
                int potentialMax = yj + xj + maxHeap.top().first;
                maxValue = max(maxValue, potentialMax);
            }

            maxHeap.emplace(yj - xj, xj);
        }

        return maxValue;
    }
};
