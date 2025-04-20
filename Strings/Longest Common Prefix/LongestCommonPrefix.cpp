class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string macthing_word = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(macthing_word) != 0) {
                macthing_word.pop_back();
            }
        }

    }
};
