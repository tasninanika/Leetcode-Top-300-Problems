class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return nullptr;

        stack<Node*> stack;
        stack.push(head);

        Node* prev = nullptr;

        while(!stack.empty()){
            Node* current = stack.top();
            stack.pop();

            if(prev){
                prev->next = current;
                current->prev = prev;
            }

            if(current->next){
                stack.push(current->next);
            }

            if(current->child){
                stack.push(current->child);
                current->child = nullptr;
            }

            prev = current;
        }

        return head;
    }
};
