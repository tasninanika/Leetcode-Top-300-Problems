class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        do {
            slow = slow->next;
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
            }
            else {
                return nullptr;
            }
        }
        while (slow != fast);

        ListNode* start = head;
        while (start != slow) {
            start = start->next;
            slow = slow->next;
        }

        return start;
    }
};
