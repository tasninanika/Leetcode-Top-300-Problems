class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int totalGas = 0, currentGas = 0, startStation = 0;

        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];

            if (currentGas < 0) {
                startStation = i + 1;
                currentGas = 0;
            }
        }

        return totalGas >= 0 ? startStation : -1;
    }
};
