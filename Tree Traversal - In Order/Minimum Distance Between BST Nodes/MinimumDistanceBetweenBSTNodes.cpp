class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prevVal = -1;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            if (prevVal != -1) {
                minDiff = min(minDiff, node->val - prevVal);
            }
            prevVal = node->val;
            inorder(node->right);
        };

        inorder(root);
        return minDiff;
    }
};

