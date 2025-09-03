class Solution {
public:
    unordered_map<string, string> parent;

    string find(string s) {
        if (parent[s] != s) {
            parent[s] = find(parent[s]);
        }
        return parent[s];
    }

    void unionSet(string a, string b) {
        string rootA = find(a);
        string rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;

        for (const auto& account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                parent[account[i]] = account[i];
                emailToName[account[i]] = account[0];
            }
        }

        for (const auto& account : accounts) {
            string rootEmail = account[1];
            for (int i = 2; i < account.size(); ++i) {
                unionSet(rootEmail, account[i]);
            }
        }

        unordered_map<string, set<string>> rootToEmails;
        for (const auto& [email, _] : emailToName) {
            string root = find(email);
            rootToEmails[root].insert(email);
        }

        vector<vector<string>> mergedAccounts;
        for (const auto& [root, emails] : rootToEmails) {
            vector<string> account{emailToName[root]};
            account.insert(account.end(), emails.begin(), emails.end());
            mergedAccounts.push_back(account);
        }

        return mergedAccounts;
    }
};

