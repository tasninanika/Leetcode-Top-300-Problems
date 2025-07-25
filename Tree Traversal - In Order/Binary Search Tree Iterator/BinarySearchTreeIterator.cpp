class BSTIterator {
private:
    stack<TreeNode*> nodeStack;

    void pushLeft(TreeNode* root) {
        while (root) {
            nodeStack.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }

    bool hasNext() {
        return !nodeStack.empty();
    }
};
