class Solution {
    pair<int, int> robSub(TreeNode* node) {
        if (!node) return {0, 0};

        auto left = robSub(node->left);
        auto right = robSub(node->right);

        int robCurrent = node->val + left.second + right.second;
        int skipCurrent = max(left.first, left.second) + max(right.first, right.second);

        return {robCurrent, skipCurrent};
    }

public:
    int rob(TreeNode* root) {
        auto result = robSub(root);
        return max(result.first, result.second);
    }
};
