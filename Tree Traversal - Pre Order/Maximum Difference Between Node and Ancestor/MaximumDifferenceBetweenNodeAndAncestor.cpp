class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

private:
    int dfs(TreeNode* node, int currentMax, int currentMin) {
        if (!node) return 0;

        int potentialDiff = max(abs(currentMax - node->val), abs(currentMin - node->val));

        currentMax = max(currentMax, node->val);
        currentMin = min(currentMin, node->val);

        int leftDiff = dfs(node->left, currentMax, currentMin);
        int rightDiff = dfs(node->right, currentMax, currentMin);

        return max(potentialDiff, max(leftDiff, rightDiff));
    }
};
