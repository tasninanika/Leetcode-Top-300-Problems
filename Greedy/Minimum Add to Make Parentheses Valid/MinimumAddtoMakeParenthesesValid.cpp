class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int min_add = 0;

        for (char c : s) {
            if (c == '(') {
                ++balance;
            } else {
                if (balance == 0) {
                    ++min_add;
                } else {
                    --balance;
                }
            }
        }


        return min_add + balance;
    }
};
