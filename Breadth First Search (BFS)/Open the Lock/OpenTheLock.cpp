class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        int steps = 0;

        if (dead.find("0000") != dead.end())
            return -1;

        q.push("0000");
        visited.insert("0000");

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                string current = q.front();
                q.pop();

                if (current == target)
                    return steps;

                for (int j = 0; j < 4; ++j) {
                    string next = current;
                    next[j] = (next[j] - '0' + 1) % 10 + '0';
                    if (visited.find(next) == visited.end() && dead.find(next) == dead.end()) {
                        q.push(next);
                        visited.insert(next);
                    }

                    next = current;
                    next[j] = (next[j] - '0' - 1 + 10) % 10 + '0';
                    if (visited.find(next) == visited.end() && dead.find(next) == dead.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
