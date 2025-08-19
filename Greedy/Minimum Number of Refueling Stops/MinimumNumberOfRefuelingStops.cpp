class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;

        stations.push_back({target, 0});

        int currentFuel = startFuel;
        int stops = 0;
        int prevPosition = 0;

        for (const auto& station : stations) {
            int stationPosition = station[0];
            int stationFuel = station[1];

            while (currentFuel < stationPosition - prevPosition) {
                if (maxHeap.empty()) return -1;
                currentFuel += maxHeap.top();
                maxHeap.pop();
                stops++;
            }

            currentFuel -= (stationPosition - prevPosition);
            prevPosition = stationPosition;
            maxHeap.push(stationFuel);
        }

        return stops;
    }
};
