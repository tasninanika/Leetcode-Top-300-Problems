class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

        int maxAttendable = 0;
        int lastDay = 0;

        vector<bool> isDayTaken(100001, false);

        for (auto& event : events) {
            for (int d = event[0]; d <= event[1]; ++d) {
                if (!isDayTaken[d]) {
                    isDayTaken[d] = true;
                    maxAttendable++;
                    break;
                }
            }
        }
        return maxAttendable;
    }
};
