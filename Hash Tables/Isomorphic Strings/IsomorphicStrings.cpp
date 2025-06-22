class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        char mappedST[256] = {0};
        char mappedTS[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            char sChar = s[i];
            char tChar = t[i];

            if (mappedST[sChar] == 0 && mappedTS[tChar] == 0) {
                mappedST[sChar] = tChar;
                mappedTS[tChar] = sChar;
            }
            else if (mappedST[sChar] != tChar || mappedTS[tChar] != sChar) {
                return false;
            }
        }

        return true;
    }
};
