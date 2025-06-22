class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> frequency;

        for (char c : magazine) {
            frequency[c]++;
        }

        for (char c : ransomNote) {
            if (frequency[c] <= 0) {
                return false;
            }
            frequency[c]--;
        }

        return true;
    }
};
