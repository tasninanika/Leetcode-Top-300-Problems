class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> indices;

        for (int i = 0; i < n; ++i) {
            while (!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                int idx = indices.top();
                indices.pop();
                result[idx] = i - idx;
            }
            indices.push(i);
        }

        return result;
    }
};
