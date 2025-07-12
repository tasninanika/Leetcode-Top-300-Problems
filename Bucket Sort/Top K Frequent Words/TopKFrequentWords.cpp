class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frequencyMap;
        for (const auto& word : words) {
            frequencyMap[word]++;
        }

        vector<std::pair<string, int>> freqVec(frequencyMap.begin(), frequencyMap.end());

        sort(freqVec.begin(), freqVec.end(), [](const pair<string, int>& a, const  pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });

        vector<std::string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqVec[i].first);
        }

        return result;
    }
};
