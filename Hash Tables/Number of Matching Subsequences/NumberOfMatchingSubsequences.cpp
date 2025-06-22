class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        array<list<pair<string::iterator, string::iterator>>, 26> waiting;

        for (auto &word : words) {
            waiting[word[0] - 'a'].emplace_back(word.begin(), word.end());
        }

        int count = 0;
        for (char c : s) {
            auto currentBucket = waiting[c - 'a'];
            waiting[c - 'a'].clear();

            for (auto it : currentBucket) {
                auto [curr, end] = it;
                ++curr;

                if (curr == end) {
                    count++;
                }
                else {
                    waiting[*curr - 'a'].emplace_back(curr, end);
                }
            }
        }
        return count;
    }
};

