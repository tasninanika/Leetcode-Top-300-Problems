class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words){
        vector<int> result;
        if(s.empty() || words.empty())
            return result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int totalLength = wordLength * wordCount;
        unordered_map<string, int> wordMap, currentMap;

        for(const auto& word : words){
            wordMap[word]++;
        }

        for(int i = 0; i < wordLength; i++){
            int left = i, count = 0;
            currentMap.clear();

            for(int right = i; right <= (int)s.size() - wordLength; right += wordLength){
                string word = s.substr(right, wordLength);

                if(wordMap.count(word)){
                    currentMap[word]++;
                    count++;

                    while(currentMap[word] > wordMap[word]){
                        string leftWord = s.substr(left, wordLength);
                        currentMap[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    if(count == wordCount){
                        result.push_back(left);
                    }
                }
                else{
                    currentMap.clear();
                    count = 0;
                    left = right + wordLength;
                }
            }
        }

        return result;
    }
};
