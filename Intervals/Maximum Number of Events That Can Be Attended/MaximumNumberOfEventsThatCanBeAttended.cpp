class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    int maxAttendable = 0;
    int day = events[0][0];
    size_t i = 0;

    while (!pq.empty() || i < events.size()) {
        while (i < events.size() && events[i][0] <= day) {
            pq.push(events[i][1]);
            ++i;
        }

        while (!pq.empty() && pq.top() < day) {
            pq.pop();
        }

        if (!pq.empty()) {
            pq.pop();
            maxAttendable++;
        }

        day++;
    }

    return maxAttendable;
    }
};
