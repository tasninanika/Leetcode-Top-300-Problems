class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string temp = s + "#" + rev_s;

        vector<int> kmp(temp.size(), 0);
        for (int i = 1; i < temp.size(); ++i) {
            int j = kmp[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = kmp[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            kmp[i] = j;
        }
