class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n, 0);
        stack<int> stk;

        for (int i = n - 1; i >= 0; --i) {
            int visibleCount = 0;
            while (!stk.empty() && stk.top() < heights[i]) {
                visibleCount++;
                stk.pop();
            }
            if (!stk.empty()) visibleCount++;
            result[i] = visibleCount;
            stk.push(heights[i]);
        }

        return result;
    }
};
