class FreqStack {
    std::unordered_map<int, int> freq;
    std::unordered_map<int, std::stack<int>> group;
    int maxFreq = 0;

public:
    FreqStack() {}

    void push(int x) {
        freq[x]++;

        if (freq[x] > maxFreq) {
            maxFreq = freq[x];
        }

        group[freq[x]].push(x);
    }

    int pop() {
        int x = group[maxFreq].top();
        group[maxFreq].pop();

        freq[x]--;

        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return x;
    }
};
