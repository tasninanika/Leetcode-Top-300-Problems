class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> buildableWords;
        buildableWords.insert("");
        string longestWord = "";

        for (const string& word : words) {
            if (buildableWords.count(word.substr(0, word.length() - 1))) {
                buildableWords.insert(word);
                if (word.length() > longestWord.length()) {
                    longestWord = word;
                }
            }
        }
        return longestWord;
    }
};

