class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        if (n == 0)
            return 0;

        vector<int> leftUnique(n, 0), rightUnique(n, 0);
        unordered_map<char, int> freqMap;
        int uniqueChars = 0;

        for (int i = 0; i < n; ++i) {
            if (++freqMap[s[i]] == 1) {
                ++uniqueChars;
            }
            leftUnique[i] = uniqueChars;
        }

        freqMap.clear();
        uniqueChars = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (++freqMap[s[i]] == 1) {
                ++uniqueChars;
            }
            rightUnique[i] = uniqueChars;
        }

        int goodSplits = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (leftUnique[i] == rightUnique[i + 1]) {
                ++goodSplits;
            }
        }

        return goodSplits;
    }
};
