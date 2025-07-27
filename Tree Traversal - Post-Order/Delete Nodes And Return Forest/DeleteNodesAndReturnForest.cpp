class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        function<TreeNode*(TreeNode*, bool)> dfs = [&](TreeNode* node, bool is_root) -> TreeNode* {
            if (!node) return nullptr;

            bool deleted = (to_delete_set.count(node->val) > 0);
            if (is_root && !deleted) {
                forest.push_back(node);
            }

            node->left = dfs(node->left, deleted);
            node->right = dfs(node->right, deleted);

            return deleted ? nullptr : node;
        };

        dfs(root, true);

        return forest;
    }
};
