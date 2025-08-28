class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<pair<string, int>> bfsQueue;
        bfsQueue.push({beginWord, 1});

        while (!bfsQueue.empty()) {
            string currentWord = bfsQueue.front().first;
            int level = bfsQueue.front().second;
            bfsQueue.pop();

            for (int i = 0; i < currentWord.length(); ++i) {
                string transformedWord = currentWord;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    transformedWord[i] = ch;
                    if (transformedWord == currentWord) continue;
                    if (transformedWord == endWord) return level + 1;

                    if (wordSet.find(transformedWord) != wordSet.end()) {
                        bfsQueue.push({transformedWord, level + 1});
                        wordSet.erase(transformedWord);
                    }
                }
            }
        }

        return 0;
    }
};
