class MinStack {
private:
    stack<pair<int, int>> stack;

public:
    MinStack() {
    }

    void push(int x) {
        if (stack.empty()) {
            stack.push({x, x});
        }
        else {
            int currentMin = std::min(stack.top().second, x);
            stack.push({x, currentMin});
        }
    }

    void pop() {
        stack.pop();
    }

    int top() {
        return stack.top().first;
    }

    int getMin() {
        return stack.top().second;
    }
};
