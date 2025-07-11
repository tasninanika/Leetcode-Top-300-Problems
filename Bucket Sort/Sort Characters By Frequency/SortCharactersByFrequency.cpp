class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        int maxFreq = 0;
        for (auto& pair : freqMap) {
            maxFreq = max(maxFreq, pair.second);
        }

        vector<vector<char>> buckets(maxFreq + 1);
        for (auto& pair : freqMap) {
            buckets[pair.second].push_back(pair.first);
        }

        string result;
        for (int i = maxFreq; i > 0; i--) {
            for (char c : buckets[i]) {
                result.append(i, c);
            }
        }

        return result;
    }
};
