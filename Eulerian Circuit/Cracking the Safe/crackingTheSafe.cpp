class Solution {
public:
    string crackSafe(int n, int k) {
        string start = string(n - 1, '0');
        unordered_set<string> visited;
        string result;

        dfs(start, visited, result, k, n);

        return result + start;
    }

private:
    void dfs(const string& node, unordered_set<string>& visited, string& result, int k, int n) {
        for (int i = 0; i < k; ++i) {
            string next = node + char('0' + i);
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                dfs(next.substr(1), visited, result, k, n);
                result.push_back('0' + i);
            }
        }
    }
};
