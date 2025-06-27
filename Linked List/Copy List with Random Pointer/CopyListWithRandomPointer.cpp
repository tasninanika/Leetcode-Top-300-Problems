class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        Node* current = head;
        while (current) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        current = head;
        while (current) {
            current->next->random = current->random ? current->random->next : nullptr;
            current = current->next->next;
        }

        Node* copyHead = head->next;
        Node* copyCurrent = copyHead;
        current = head;

        while (current) {
            current->next = current->next->next;
            copyCurrent->next = copyCurrent->next ? copyCurrent->next->next : nullptr;
            current = current->next;
            copyCurrent = copyCurrent->next;
        }

        return copyHead;
    }
};
