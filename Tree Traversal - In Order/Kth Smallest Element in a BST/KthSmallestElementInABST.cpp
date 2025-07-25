class Solution {
public:
    int inorderTraversal(TreeNode* root, int& k) {
        if (root == nullptr) return -1;

        int left = inorderTraversal(root->left, k);
        if (k == 0) return left;

        k--;
        if (k == 0) return root->val;

        return inorderTraversal(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return inorderTraversal(root, k);
    }
};
