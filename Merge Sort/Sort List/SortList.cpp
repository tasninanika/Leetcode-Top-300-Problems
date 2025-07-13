class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* curr = head;
        int list_size = 0;
        while (curr) {
            list_size++;
            curr = curr->next;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* tail;
        ListNode* left;
        ListNode* right;
        ListNode* nextSublist;

        for (int step = 1; step < list_size; step <<= 1) {
            curr = dummy->next;
            tail = dummy;

            while (curr) {
                left = curr;
                right = split(left, step);
                nextSublist = split(right, step);
                tail = merge(left, right, tail);
                curr = nextSublist;
            }
        }

        return dummy->next;
    }

    ListNode* split(ListNode* head, int size) {
        ListNode* temp = head;
        for (int i = 1; temp && i < size; i++) {
            temp = temp->next;
        }
        if (!temp) return nullptr;

        ListNode* second = temp->next;
        temp->next = nullptr;
        return second;
    }

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* tail) {
        ListNode* curr = tail;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        while (curr->next) {
            curr = curr->next;
        }
        return curr;
    }
};
