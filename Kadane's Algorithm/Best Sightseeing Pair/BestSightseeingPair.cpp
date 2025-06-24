class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int bestValue_i = values[0];

        for (int j = 1; j < values.size(); j++) {
            maxScore = max(maxScore, bestValue_i + values[j] - j);
            bestValue_i = max(bestValue_i, values[j] + j);
        }
        return maxScore;
    }
};
