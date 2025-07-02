class Solution {
public:
    bool isValid(string s) {
        stack<char> matchStack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                matchStack.push(c);
            }
            else {
                if (matchStack.empty() ||
                    (c == ')' && matchStack.top() != '(') ||
                    (c == ']' && matchStack.top() != '[') ||
                    (c == '}' && matchStack.top() != '{')) {
                    return false;
                }
                matchStack.pop();
            }
        }
        return matchStack.empty();
    }
};
