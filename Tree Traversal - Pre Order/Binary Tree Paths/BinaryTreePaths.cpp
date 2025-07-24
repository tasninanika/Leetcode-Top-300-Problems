class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root == nullptr) return paths;
        traverseTree(root, "", paths);
        return paths;
    }

private:
    void traverseTree(TreeNode* node, string path, vector<string>& paths) {
        if (!node) return;

        path += to_string(node->val);

        if (!node->left && !node->right) {
            paths.push_back(path);
        } else {
            path += "->";
            traverseTree(node->left, path, paths);
            traverseTree(node->right, path, paths);
        }
    }
};
