class Solution {
public:
    int pathSumHelper(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSumCount) {
        if (!node) return 0;

        currentSum += node->val;
        int numPathsToCurr = prefixSumCount[currentSum - targetSum];

        prefixSumCount[currentSum]++;
        numPathsToCurr += pathSumHelper(node->left, currentSum, targetSum, prefixSumCount);
        numPathsToCurr += pathSumHelper(node->right, currentSum, targetSum, prefixSumCount);
        prefixSumCount[currentSum]--;

        return numPathsToCurr;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1;
        return pathSumHelper(root, 0, targetSum, prefixSumCount);
    }
};

