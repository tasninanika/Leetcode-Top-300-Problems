class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while(curr != nullptr && count < k){
            curr = curr->next;
            count++;
        }

        if(count == k){
            ListNode* reversedHead = reverseKGroup(curr, k);

            while(count-- > 0){
                ListNode* temp = head->next;
                head->next = reversedHead;
                reversedHead = head;
                head = temp;
            }
            head = reversedHead;
        }
        return head;
    }
};
