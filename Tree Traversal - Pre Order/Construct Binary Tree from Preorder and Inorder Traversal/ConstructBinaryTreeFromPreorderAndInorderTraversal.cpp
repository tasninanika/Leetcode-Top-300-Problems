class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        return buildSubTree(preorder, 0, 0, inorder.size() - 1, inorderMap);
    }

private:
    TreeNode* buildSubTree(vector<int>& preorder, int preStart, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        if (preStart >= preorder.size() || inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = inorderMap[rootVal];

        root->left = buildSubTree(preorder, preStart + 1, inStart, inRootIndex - 1, inorderMap);

        int leftTreeSize = inRootIndex - inStart;
        root->right = buildSubTree(preorder, preStart + leftTreeSize + 1, inRootIndex + 1, inEnd, inorderMap);

        return root;
    }
};
