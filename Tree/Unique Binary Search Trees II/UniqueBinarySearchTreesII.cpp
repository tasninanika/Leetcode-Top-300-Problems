class Solution {
private:
    unordered_map<string, vector<TreeNode*>> memo;

    string getKey(int start, int end) {
        return to_string(start) + "-" + to_string(end);
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildBST(1, n);
    }

    vector<TreeNode*> buildBST(int start, int end) {
        vector<TreeNode*> allTrees;

        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }

        string key = getKey(start, end);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = buildBST(start, i - 1);

            vector<TreeNode*> rightTrees = buildBST(i + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* currentTree = new TreeNode(i);
                    currentTree->left = left;
                    currentTree->right = right;
                    allTrees.push_back(currentTree);
                }
            }
        }

        memo[key] = allTrees;

        return allTrees;
    }
};
