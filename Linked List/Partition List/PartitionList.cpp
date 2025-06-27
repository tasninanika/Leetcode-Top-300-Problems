class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode leftHead(0), rightHead(0);
        ListNode* left = &leftHead;
        ListNode* right = &rightHead;

        while (head != nullptr) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            }
            else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        right->next = nullptr;
        left->next = rightHead.next;

        return leftHead.next;
    }
};
