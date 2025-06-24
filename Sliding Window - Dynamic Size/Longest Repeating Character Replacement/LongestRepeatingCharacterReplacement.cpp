class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> c(26, 0);
        int max_count = 0;
        int start = 0;
        int max_length = 0;

        for(int end = 0; end < s.size(); end++) {
            max_count = max(max_count, ++c[s[end] - 'A']);

            while((end - start + 1) - max_count > k) {
                c[s[start] - 'A']--;
                start++;
            }

            max_length = max(max_length, end - start + 1);
        }
        return max_length;
    }
};
