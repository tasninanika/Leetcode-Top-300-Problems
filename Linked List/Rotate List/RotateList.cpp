class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0)
            return head;

        int length = 1;
        ListNode* lastNode = head;

        while(lastNode->next){
            lastNode = lastNode->next;
            length++;
        }

        lastNode->next = head;

        int stepsToNewHead = length - k % length;
        ListNode* newTail = head;

        for(int i = 1; i < stepsToNewHead; i++){
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
