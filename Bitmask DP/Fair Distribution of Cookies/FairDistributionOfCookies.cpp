class Solution {
public:
    void distribute(int index, vector<int>& cookies, vector<int>& distribution, int& minUnfairness) {
        if (index == cookies.size()) {
            int maxCookies = *max_element(distribution.begin(), distribution.end());
            minUnfairness = min(minUnfairness, maxCookies);
            return;
        }

        for (int i = 0; i < distribution.size(); ++i) {
            distribution[i] += cookies[index];
            distribute(index + 1, cookies, distribution, minUnfairness);
            distribution[i] -= cookies[index];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribution(k, 0);
        int minUnfairness = INT_MAX;
        distribute(0, cookies, distribution, minUnfairness);
        return minUnfairness;
    }
};
