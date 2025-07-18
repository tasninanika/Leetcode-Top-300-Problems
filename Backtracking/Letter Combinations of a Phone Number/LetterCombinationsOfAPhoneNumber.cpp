class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        const vector<string> keypad = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        vector<string> results;
        string currentCombination;

        backtrack(digits, 0, keypad, currentCombination, results);

        return results;
    }

private:
    void backtrack(const string& digits, int index, const vector<string>& keypad, string& currentCombination, vector<string>& results) {
        if (index == digits.size()) {
            results.push_back(currentCombination);
            return;
        }

        int digit = digits[index] - '0';
        const string& possibleChars = keypad[digit];

        for (char ch : possibleChars) {
            currentCombination.push_back(ch);
            backtrack(digits, index + 1, keypad, currentCombination, results);
            currentCombination.pop_back();
        }
    }
};
