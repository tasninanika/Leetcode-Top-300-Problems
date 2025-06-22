class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count = {{'b', 0}, {'a', 0}, {'l', 0}, {'o', 0}, {'n', 0}};

        for (char ch : text) {
            if (count.find(ch) != count.end()) {
                count[ch]++;
            }
        }

        count['l'] /= 2;
        count['o'] /= 2;

        int maxBalloons = INT_MAX;
        for (auto& p : count) {
            maxBalloons = min(maxBalloons, p.second);
        }
        return maxBalloons;
    }
};
