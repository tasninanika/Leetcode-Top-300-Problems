class Solution {
public:
    int computeTreeHeight(TreeNode* node) {
        int height = 0;
        while (node != nullptr) {
            height++;
            node = node->left;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftHeight = computeTreeHeight(root->left);
        int rightHeight = computeTreeHeight(root->right);

        if (leftHeight == rightHeight) {
            return (1 << leftHeight) + countNodes(root->right);
        }
        else {
            return (1 << rightHeight) + countNodes(root->left);
        }
    }
};
