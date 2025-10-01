class Solution {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        int sIndex = 0, pIndex = 0;
        int starIndex = -1, sTmp = -1;

        while (sIndex < s.length()) {
            if (pIndex < p.length() && (p[pIndex] == s[sIndex] || p[pIndex] == '?')) {
                ++sIndex;
                ++pIndex;
            }
            else if (pIndex < p.length() && p[pIndex] == '*') {
                starIndex = pIndex;
                sTmp = sIndex;
                ++pIndex;
            } else if (starIndex != -1) {
                pIndex = starIndex + 1;
                sIndex = sTmp + 1;
                sTmp = sIndex;
            } else {
                return false;
            }
        }

        while (pIndex < p.length() && p[pIndex] == '*') {
            ++pIndex;
        }

        return pIndex == p.length();
    }
};
