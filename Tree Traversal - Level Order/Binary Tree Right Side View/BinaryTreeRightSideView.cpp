class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        dfs(root, 0, rightView);
        return rightView;
    }

private:
    void dfs(TreeNode* node, int level, vector<int>& rightView) {
        if (node == nullptr) return;

        if (level == rightView.size())
            rightView.push_back(node->val);

        dfs(node->right, level + 1, rightView);
        dfs(node->left, level + 1, rightView);
    }
};
