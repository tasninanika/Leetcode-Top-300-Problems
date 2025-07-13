class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;

        auto findMiddle = [](ListNode* start) {
            ListNode *prevPtr = nullptr, *slowPtr = start, *fastPtr = start;

            while (fastPtr && fastPtr->next) {
                prevPtr = slowPtr;
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next->next;
            }
            if (prevPtr) prevPtr->next = nullptr;

            return slowPtr;
        };

        ListNode* mid = findMiddle(head);

        TreeNode* root = new TreeNode(mid->val);

        if (head == mid) {
            return root;
        }

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }
};
