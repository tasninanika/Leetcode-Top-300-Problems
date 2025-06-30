class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right){
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        for(int i = 1; i < left; ++i){
            prev = prev->next;
        }

        ListNode* current = prev->next;
        ListNode* nextNode = current->next;

        for(int i = 0; i < right - left; i++){
            current->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
            nextNode = current->next;
        }

        return dummy->next;
    }
};
