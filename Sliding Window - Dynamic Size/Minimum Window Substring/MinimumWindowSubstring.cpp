class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        unordered_map<char, int> tFreq, windowFreq;

        for (char c : t)
            tFreq[c]++;

        int start = 0, minLen = INT_MAX, count = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            windowFreq[c]++;

            if (tFreq.count(c) && windowFreq[c] <= tFreq[c])
                count++;

            while (count == t.length()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char startChar = s[left];
                if (tFreq.count(startChar)) {
                    windowFreq[startChar]--;
                    if (windowFreq[startChar] < tFreq[startChar])
                        count--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
