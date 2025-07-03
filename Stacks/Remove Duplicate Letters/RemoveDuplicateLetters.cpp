class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        vector<bool> visited(26, false);
        stack<char> stack;

        for (char c : s) {
            freq[c]++;
        }

        for (char c : s) {
            freq[c]--;

            if (visited[c - 'a'])
                continue;

            while (!stack.empty() && stack.top() > c && freq[stack.top()] > 0) {
                visited[stack.top() - 'a'] = false;
                stack.pop();
            }

            stack.push(c);
            visited[c - 'a'] = true;
        }

        string result;
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }

        return result;

    }
};
