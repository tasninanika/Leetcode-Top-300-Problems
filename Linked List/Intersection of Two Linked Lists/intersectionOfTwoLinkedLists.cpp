class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodes_set;

        while(headA != nullptr){
            nodes_set.insert(headA);
            headA = headA->next;
        }

        while(headB != nullptr){
            if(nodes_set.count(headB)){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};
