class Solution {
public:
    vector<int> cumulativeWeights;
    int totalWeight;

    Solution(vector<int>& w) {
        cumulativeWeights.resize(w.size());
        cumulativeWeights[0] = w[0];

        for (int i = 1; i < w.size(); ++i) {
            cumulativeWeights[i] = cumulativeWeights[i - 1] + w[i];
        }
        totalWeight = cumulativeWeights.back();
    }

    int pickIndex() {
        int target = rand() % totalWeight;

        int low = 0, high = cumulativeWeights.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (target < cumulativeWeights[mid]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};


