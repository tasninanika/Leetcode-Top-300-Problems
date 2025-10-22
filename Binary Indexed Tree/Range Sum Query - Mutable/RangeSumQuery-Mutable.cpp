class NumArray {
private:
    vector<int> tree;
    int n;

    void buildTree(const vector<int>& nums, int treeIndex, int start, int end) {
        if (start == end) {
            tree[treeIndex] = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(nums, 2 * treeIndex + 1, start, mid);
        buildTree(nums, 2 * treeIndex + 2, mid + 1, end);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }


