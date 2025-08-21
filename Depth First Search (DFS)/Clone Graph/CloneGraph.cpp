class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> visited;

        queue<Node*> q;

        Node* clone = new Node(node->val);
        visited[node] = clone;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (auto neighbor : current->neighbors) {
                if (!visited.count(neighbor)) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[current]->neighbors.push_back(visited[neighbor]);
            }
        }

        return clone;
    }
};
