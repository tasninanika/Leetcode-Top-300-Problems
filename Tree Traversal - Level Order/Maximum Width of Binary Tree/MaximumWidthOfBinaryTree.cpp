class Solution {
public:
    void dfs(TreeNode* node, unsigned long long index, int depth, unsigned long long &maxWidth, map<int, unsigned long long> &firstColIndexMap) {
        if (!node) return;

        if (firstColIndexMap.find(depth) == firstColIndexMap.end()) {
            firstColIndexMap[depth] = index;
        }

        maxWidth = max(maxWidth, index - firstColIndexMap[depth] + 1);

        dfs(node->left, 2 * index, depth + 1, maxWidth, firstColIndexMap);
        dfs(node->right, 2 * index + 1, depth + 1, maxWidth, firstColIndexMap);
    }

    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long maxWidth = 0;
        map<int, unsigned long long> firstColIndexMap;
        dfs(root, 1, 0, maxWidth, firstColIndexMap);
        return maxWidth;
    }
};
