class Solution {
public:
    int solve(string& s1, string& s2){
            int c = 0;
            for (int i = 0; i < 6; i++){
                if (s1[i] == s2[i]){
                    c++;
                }
            }
            return c;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        srand(time(0));
        int n = words.size();
        for(int i = 0; i < 30; i++) {
            int idx = rand() % words.size();
            int matchedVal = master.guess(words[idx]);
            if(matchedVal == 6) {
                    break;
            }
            vector<string> candidates;
            string guessedWord = words[idx];





    }
};
