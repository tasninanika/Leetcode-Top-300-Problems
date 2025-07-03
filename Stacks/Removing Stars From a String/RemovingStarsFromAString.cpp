class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for (char ch : s) {
            if (ch == '*') {
                if (j > 0) {
                    j--;
                }
            }
            else {
                s[j++] = ch;
            }
        }
        return s.substr(0, j);
    }
};
