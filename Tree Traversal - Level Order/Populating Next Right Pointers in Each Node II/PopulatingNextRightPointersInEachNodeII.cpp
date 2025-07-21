class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* head = root;

        while (head != nullptr) {
            Node* dummy = new Node();
            Node* tail = dummy;

            for (Node* current = head; current != nullptr; current = current->next) {
                if (current->left) {
                    tail->next = current->left;
                    tail = tail->next;
                }
                if (current->right) {
                    tail->next = current->right;
                    tail = tail->next;
                }
            }

            head = dummy->next;
            delete dummy;
        }

        return root;
    }
};
