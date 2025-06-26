class MyLinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;

            while(current->next){
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val){
        if(index < 0 || index > size)
            return;

        if(index == 0){
            addAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* current = head;

        for(int i = 0; i < index - 1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;

        Node* toDelete;
        if (index == 0) {
            toDelete = head;
            head = head->next;
        }
        else{
            Node* current = head;
            for(int i = 0; i < index - 1; i++){
                current = current->next;
            }
            toDelete = current->next;
            current->next = current->next->next;
        }
        delete toDelete;
        size--;
    }
};
