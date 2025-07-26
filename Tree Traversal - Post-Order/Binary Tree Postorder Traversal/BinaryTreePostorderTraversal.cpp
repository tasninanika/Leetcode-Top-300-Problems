class Solution {
public:
    void postorderTraversalHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr)
            return;
        postorderTraversalHelper(node->left, result);
        postorderTraversalHelper(node->right, result);
        result.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTraversalHelper(root, result);
        return result;
    }
};
