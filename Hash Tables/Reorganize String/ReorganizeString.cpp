class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> frequency;
        int n = s.size();

        for (char c : s) {
            frequency[c]++;
        }

        vector<pair<int, char>> freq_chars;
        for (auto& elem : frequency) {
            freq_chars.push_back({elem.second, elem.first});
        }

        sort(freq_chars.rbegin(), freq_chars.rend());

        if (freq_chars[0].first > (n + 1) / 2)
            return "";

        string result(n, ' ');

        int index = 0;
        for (auto& [freq, char_val] : freq_chars) {
            for (int count = 0; count < freq; ++count) {
                if (index >= n) {
                    index = 1;
                }
                result[index] = char_val;
                index += 2;
            }
        }

        return result;
    }
};
