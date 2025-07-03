class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            }

            if (!isdigit(c) && !isspace(c) || i == n - 1) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                }
                else if (operation == '+') {
                    stack.push(currentNumber);
                }
                else if (operation == '*') {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top * currentNumber);
                }
                else if (operation == '/') {
                    int top = stack.top();
                    stack.pop();
                    stack.push(top / currentNumber);
                }
                operation = c;
                currentNumber = 0;
            }
        }

        int result = 0;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }

        return result;
    }
};
