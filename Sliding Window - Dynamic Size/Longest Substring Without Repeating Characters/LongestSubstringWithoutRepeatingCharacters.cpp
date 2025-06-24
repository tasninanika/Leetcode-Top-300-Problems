class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeenIndex;
        int maxLength = 0;
        int start = 0;

        for(int end = 0; end < s.size(); ++end){
            if(lastSeenIndex.find(s[end]) != lastSeenIndex.end() && lastSeenIndex[s[end]] >= start) {
                start = lastSeenIndex[s[end]] + 1;
            }
            lastSeenIndex[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};
