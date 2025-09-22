class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        vector<int> dp(n);
        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            int inclProfit = jobs[i][2];
            int l = binarySearch(jobs, i);
            if (l != -1) {
                inclProfit += dp[l];
            }
            dp[i] = max(dp[i - 1], inclProfit);
        }

        return dp[n - 1];
    }

private:
    int binarySearch(const vector<vector<int>>& jobs, int index) {
        int low = 0, high = index - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid][0] <= jobs[index][1]) {
                if (jobs[mid + 1][0] <= jobs[index][1]) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
