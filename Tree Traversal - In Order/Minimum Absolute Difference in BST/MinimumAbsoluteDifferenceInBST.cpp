class Solution {
public:
    void inOrderTraversal(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inOrderTraversal(root->left, vals);
        vals.push_back(root->val);
        inOrderTraversal(root->right, vals);
    }

    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;

        vector<int> vals;
        inOrderTraversal(root, vals);

        int minDiff = INT_MAX;
        for (int i = 1; i < vals.size(); ++i) {
            minDiff = min(minDiff, vals[i] - vals[i - 1]);
        }

        return minDiff;
    }
};
