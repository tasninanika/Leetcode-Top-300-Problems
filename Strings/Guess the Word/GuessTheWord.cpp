class Solution {
public:
    int solve(string s1, string s2){
            int ans = 0;
            for (int i = 0; i < s1.size(); i++){
                if (s1[i] == s2[i]){
                    ans++;
                }
            }
            return ans;
    }

    void findSecretWord(vector<string>& words, Master& master) {




    }
};
